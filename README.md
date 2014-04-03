# Grand Racing Game

This repository contains all files required to set up the Grand Racing Game San Andreas Multiplayer server.

Visit http://grgserver.net for more information about the server.

# How to run the server

## Requirements

  * Linux or Windows
  * MySQL Server
  * Webserver (To stream the audio files)
  * x64 Linux only: libc6-i386 (To run the Pawn compiler)
  * A current [JDK](http://www.oracle.com/technetwork/java/javase/downloads/index.html) (To build and execute tools like the Includes Updater)

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

## Configuration

  * Clone this repository
  * Copy server.sample.cfg to server.cfg and edit it to fit your needs
  * Copy localconfig.sample.inc in includes/grgserver to localconfig.inc and edit it to fit your needs
  * Compile the grgserver.pwn located in the gamemodes folder (See section **Compiling the script** bellow)
  * Import the database schema into your MySQL database
  * Start the server

## Compiling the script

[![Build Status](https://travis-ci.org/GRGServer/SAMPRacing.svg)](https://travis-ci.org/GRGServer/SAMPRacing)

### Windows

**Note:** Run the Includes Updater before compiling the script! (See section *Includes Updater* bellow)

To compile the script you just have to execute the following commands:

```
cd gamemodes
../tools/pawn/pawncc.exe grgserver.pwn -i../includes -; -(
cd ../npcmodes
../tools/pawn/pawncc.exe npcplayer.pwn -i../includes -; -(
```

### Linux

Just execute the *compile-gamemode.sh* shell script located in the tools directory.

The script will build the Includes Updater using maven, execute it and build the Gamemode.

## Includes Updater

The Includes Updater searches for all the include files in */includes/grgserver* and includes them into the *main.inc*.

As any other Java tool, the Includes Updater has to be build using Maven before using it:

```
cd tools/includesupdater
../apache-maven/bin/mvn clean package
```

After that the *includesupdater.jar* is located in the *target* directory. Keep it in that directory! Execute it using *java -jar target/includesupdater.jar*

## Notes for Linux

On Linux you have to manually set the executable bit on executables (*chmod +x*):

```
chmod +x announce samp-npc samp-srv tools/*.sh tools/pawn/pawncc
```

When doing that you should disable *core.fileMode* in your git config to prevent marking the files as changed:

```
git config core.fileMode false
```
