# Grand Racing Game

This repository contains all files required to set up the Grand Racing Game San Andreas Multiplayer server.

Visit http://grgserver.net for more information about the server.

## Used plugins

The following plugins are used by the server:

 * [crashdetect](http://forum.sa-mp.com/showthread.php?t=262796)
 * [filemanager](http://forum.sa-mp.com/showthread.php?t=92246)
 * [geoip](http://forum.sa-mp.com/showthread.php?t=32509)
 * [mysql](http://forum.sa-mp.com/showthread.php?t=56564)
 * [sscanf](http://forum.sa-mp.com/showthread.php?t=120356)
 * [streamer](http://forum.sa-mp.com/showthread.php?t=102865)
 * [whirlpool](http://forum.sa-mp.com/showthread.php?t=65290)
 * [xml](http://forum.sa-mp.com/showthread.php?t=372521)

## Running in Vagrant VM

You can omit the other setup steps by using the provided Vagrant VM based on Debian Stretch.

Before continuing, you have to install the following Vagrant plugins (if not already installed):

* VirtualBox guest plugin: `vagrant plugin install vagrant-vbguest`
* Puppet install plugin: `vagrant plugin install vagrant-puppet-install`

Simply execute `vagrant up` in the root directory of your checkout to start the Vagrant VM.

This will automatically setup the whole server (including MySQL and the webserver) and compile the gamemode.

Once the VM is running, simply add `localhost:7777` to your favorites and you are ready to start.

Unfortunately, the SA-MP server is now only reachable via *localhost*, it is not even reachable via *127.0.0.1*. One workaround for this issue is to manually specify the network interface IP address as *Host IP* in the port forwarding settings of the VM in VirtualBox.

## Requirements

  * Linux
  * MySQL Server
  * Webserver (To stream the audio files and display the online map)
  * PHP (To display the online map)
  * To use Pawn on x64 Linux: 32-bit C Library for AMD64 (*apt-get install libc6-i386* on Debian based Linux distributions)
  * Optional: A current [JDK](http://www.oracle.com/technetwork/java/javase/downloads/index.html) (To build and execute tools like the Language String Editor)

## Configuration

  * Clone this repository
  * Copy [server.sample.cfg](server.sample.cfg) to server.cfg and edit it to fit your needs
  * Copy [mysql.sample.ini](mysql.sample.ini) to mysql.ini and configure in the hostname, username, password and database for you MySQL database
  * Copy [localconfig.sample.inc](includes/grgserver/localconfig.sample.inc) in includes/grgserver to localconfig.inc and edit it to fit your needs
  * Compile the grgserver.pwn located in the gamemodes folder (See section **Compiling the script** bellow)
  * Import the database schema into your MySQL database
  * Start the server

## Compiling the script

[![pipeline status](https://gitlab.com/GRGServer/SAMPRacing/badges/master/pipeline.svg)](https://gitlab.com/GRGServer/SAMPRacing/commits/master)

Just execute `compile-gamemode.sh` located in the tools directory.

The script will execute the Includes Updater (*tools/update-includes.py*) and compile the gamemode.

## Compiling tools

Some tools have to be compiled before using them.

Simply execute `compile-tools.sh` and you are done.

**Note:** Everytime a tool gets changed it has to be rebuilt. In this case, simply re-execute the script.

## Map

The map located in the *map* directory shows all currently online players on a map.

**Note:** On the first use you have to generate the map tiles using the *generate-tiles.php* PHP script (Run it from the command line using `php generate-tiles.php`).

**Note:** The map requires a webserver running PHP on the same host as the SA-MP server because the PHP scripts are reading files from the *scriptfiles* directory!