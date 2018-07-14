$packages = [
  "apt-transport-https",
  "ca-certificates",
  "git",
  "htop",
  "libc6-i386",
  "vim",
]

package { $packages: }

exec { "apt_add_i386":
  command => "/usr/bin/dpkg --add-architecture i386",
  notify  => Class["apt::update"],
}

package { ["libstdc++6:i386", "libgcc1:i386", "zlib1g:i386", "libncurses5:i386"]:
  before  => Service["samp"],
  require => Class["apt::update"],
}

apt::source { "packages.sury.org_php":
  location => "https://packages.sury.org/php",
  release  => "stretch",
  repos    => "main",
  key      => {
    id     => "DF3D585DB8F0EB658690A554AC0E47584A7A714D",
    source => "https://packages.sury.org/php/apt.gpg",
  },
  require  => Package["apt-transport-https", "ca-certificates"],
}

apt::pin { "packages.sury.org_php":
  priority   => 1000,
  originator => "deb.sury.org",
  require    => Class["apt::update"],
}

$php_modules = [
  "cli",
  "mysql",
  "xml"
]

$php_modules.each | $module | {
  package { "php7.2-${module}":
    require => [
      Class["apt::update"],
      Apt::Pin["packages.sury.org_php"],
    ],
  }
}

class { "apache":
  mpm_module    => "prefork",
  default_vhost => false,
  manage_user   => false,
  user          => "vagrant",
  group         => "vagrant",
}

package { "libapache2-mod-php7.2":
  require => [
    Class["apache"],
    Class["apt::update"],
    Apt::Pin["packages.sury.org_php"],
  ],
}

class { "apache::mod::php":
  php_version => "7.2",
}
include apache::mod::rewrite

apache::vhost { "localhost":
  port     => 80,
  docroot  => "/opt/samp/map",
  override => ["All"],
}

class { "mysql::server":
  remove_default_accounts => true,
}

mysql::db { "samp":
  dbname   => "samp",
  user     => "samp",
  password => "samp",
  host     => "localhost",
  grant    => ["SELECT", "INSERT", "UPDATE", "DELETE"],
  sql      => "/opt/samp/database.sql",
}

file { "/etc/systemd/system/samp.service":
  source => "/opt/samp/vagrant/samp.service",
  notify => Exec["reload-systemd"],
}

exec { "reload-systemd":
  command     => "/bin/systemctl daemon-reload",
  refreshonly => true,
}

file { "/opt/samp/server.cfg":
  source  => "/opt/samp/vagrant/server.cfg",
}

exec { "compile_gamemode":
  command => "/opt/samp/tools/compile-gamemode.sh",
  require => Package["libc6-i386"],
}

file { "/opt/samp/mysql.ini":
  source  => "/opt/samp/vagrant/mysql.ini",
}

service { "samp":
  ensure  => running,
  enable  => true,
  require => [
    File[
      "/etc/systemd/system/samp.service",
      "/opt/samp/server.cfg",
      "/opt/samp/mysql.ini",
    ],
    Exec["reload-systemd"],
    Mysql::Db["samp"],
  ],
}
