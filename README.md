# Grand Racing Game

This repository contains all files required to set up the Grand Racing Game San Andreas Multiplayer server.

Visit http://grgserver.net for more information about the server.

## Used plugins

The following plugins are used by the server:

 * [crashdetect](http://forum.sa-mp.com/showthread.php?t=262796)
 * [filemanager](http://forum.sa-mp.com/showthread.php?t=92246)
 * [geoip](http://forum.sa-mp.com/showthread.php?t=32509)
 * [mysql](http://forum.sa-mp.com/showthread.php?t=56564)
 * [regex](http://forum.sa-mp.com/showthread.php?t=247893)
 * [sscanf](http://forum.sa-mp.com/showthread.php?t=120356)
 * [streamer](http://forum.sa-mp.com/showthread.php?t=102865)
 * [whirlpool](http://forum.sa-mp.com/showthread.php?t=65290)
 * [xml](http://forum.sa-mp.com/showthread.php?t=372521)

## Requirements

  * Linux or Windows
  * MySQL Server
  * Webserver (To stream the audio files and display the online map)
  * PHP (To display the online map)
  * To use Pawn on x64 Linux: 32-bit C Library for AMD64 (*apt-get install libc6-i386* on Debian based Linux distributions)
  * A current [JDK](http://www.oracle.com/technetwork/java/javase/downloads/index.html) (To build and execute tools like the Includes Updater)

## Configuration

  * Clone this repository
  * Copy server.sample.cfg to server.cfg and edit it to fit your needs
  * Copy localconfig.sample.inc in includes/grgserver to localconfig.inc and edit it to fit your needs
  * Compile the grgserver.pwn located in the gamemodes folder (See section **Compiling the script** bellow)
  * Import the database schema into your MySQL database
  * Start the server

## Compiling the script

[![Build Status](https://travis-ci.org/GRGServer/SAMPRacing.svg)](https://travis-ci.org/GRGServer/SAMPRacing)

Just execute *compile-gamemode.bat* (Windows) or *compile-gamemode.sh* (Linux) located in the tools directory.

The script will execute the Includes Updater (See section *Includes Updater* bellow) and compile the gamemode.

## Includes Updater

The Includes Updater searches for all the include files in */includes/grgserver* and includes them into the *main.inc*.

As any other Java tool, the Includes Updater has to be build using Maven before using it (See section *Compiling tools*).

After that the *includesupdater.jar* is located in *includesupdater/target*. Keep it in that directory! Execute it using *java -jar path/to/target/includesupdater.jar*

## Compiling tools

Some tools have to be compiled before using them.

Simply execute the *compile-tools.bat* (Windows) or *compile-tools.sh* (Linux) and you are done.

**Note:** Everytime a tool gets changed it has to be rebuilt. In this case, simply re-execute the script.

## Map

The map located in /map shows all currently connected players on a map.

On the first use you have to generate the map tiles using the *generate-tiles.php* PHP script (Run it from the CLI using *php generate-tiles.php*).

The map requires a webserver running PHP on the same host as the SA-MP server!

## Notes for Linux

On Linux you have to manually set the executable bit on executables (*chmod +x*):

```
chmod +x announce samp-npc samp-srv tools/*.sh tools/apache-maven/bin/mvn tools/pawn/pawncc
```

When doing that you should disable *core.fileMode* in your git config to prevent marking the files as changed:

```
git config core.fileMode false
```
