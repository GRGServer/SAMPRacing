# Grand Racing Game

This repository contains all files required to set up the Grand Racing Game San Andreas Multiplayer server.

Visit http://grgserver.net for more information about the server.

# How to run the server

## Requirements

  * Linux or Windows
  * MySQL Server
  * Webserver (To stream the audio files)

To compile the script on Linux, you have to install wine. The Pawn compiler also requires vcrun6 and vcrun2005 which can be installed using winetricks.

```
aptitude install wine winetricks
winetricks --unattended vcrun6
winetricks --unattended vcrun2005
```

## Configuration

  * Clone this repository
  * Copy server.sample.cfg to server.cfg and edit it to fit your needs
  * Copy localconfig.sample.inc in includes/grgserver to localconfig.inc and edit it to fit your needs
  * Compile the grgserver.pwn located in the gamemodes folder (See section **Compiling the script** bellow)
  * Import the database schema into your MySQL database
  * Start the server

## Compiling the script

To compile the script on Windows you just have to execute the following commands:

```
cd gamemodes
../tools/pawn/pawncc.exe grgserver.pwn -i../includes -; -(
```

On Linux you have to use wine and escape the last two options:

```
cd gamemodes
wine ../tools/pawn/pawncc.exe grgserver.pwn -i../includes -\; -\(
```
