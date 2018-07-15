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
    config.vm.provision "shell", run: "always", inline: "systemctl restart samp"

    require "time"
    offset = ((Time.zone_offset(Time.now.zone)/60)/60)
    zone_sufix = offset >= 0 ? "-#{offset.to_s}" : "+#{offset.to_s}"
    timezone = "Etc/GMT" + zone_sufix
    config.vm.provision "shell", inline: "sudo rm -f /etc/localtime; echo \"#{timezone}\" | sudo tee /etc/timezone && dpkg-reconfigure --frontend noninteractive tzdata"
end