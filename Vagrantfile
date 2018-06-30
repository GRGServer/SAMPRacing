$script = <<SHELL
    apt-get update

    for module in {puppetlabs-apache,puppetlabs-apt,puppetlabs-mysql}; do
        puppet module install --target-dir /opt/samp/vagrant/puppet/test/modules $module
    done
SHELL

Vagrant.configure(2) do |config|
    config.vm.box = "debian/stretch64"
    config.vm.network "forwarded_port", guest: 80, host: 8080, auto_correct: true
    config.vm.network "forwarded_port", guest: 7777, host: 7777, protocol:"udp", auto_correct: true
    config.vm.synced_folder ".", "/opt/samp"
    config.vm.provision "shell",
        inline: $script
    config.vm.provision "puppet" do |puppet|
        puppet.environment_path = "vagrant/puppet"
        puppet.environment = "test"
    end
    config.puppet_install.puppet_version = "4.10.9"
end