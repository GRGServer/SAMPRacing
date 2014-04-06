@echo off

set TOOLSPATH=%~dp0
set SERVERPATH=%TOOLSPATH%..\
set PAWNCC=%TOOLSPATH%pawn\pawncc.exe

java -jar %TOOLSPATH%includesupdater\target\includesupdater.jar

%PAWNCC% grgserver.pwn -D%SERVERPATH%gamemodes -i../includes -; -(

%PAWNCC% npcplayer.pwn -D%SERVERPATH%npcmodes -i../includes -; -(