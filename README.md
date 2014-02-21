# Grand Racing Game

This repository contains all files required to set up the Grand Racing Game San Andreas Multiplayer server.

Visit http://grgserver.net for more information about the server.

# How to run the server

## Requirements

  * Windows or Linux
  * MySQL Server

## Configuration

  * Clone this repository
  * Copy server.sample.cfg to server.cfg and edit it to fit your needs
  * Copy localconfig.sample.inc in includes/grgserver to localconfig.inc and edit it to fit your needs
  * Compile the grgserver.pwn located in the gamemodes folder (See section **Compile the script** bellow)
  * Import the database schema into your MySQL database
  * Start the server

## Compiling the script

To compile the script you just have to execute the following command in the gamemodes folder:

../tools/pawn/pawncc.exe grgserver.pwn -i../includes -; -(
