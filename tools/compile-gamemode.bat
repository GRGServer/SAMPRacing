@echo off

set TOOLSPATH=%~dp0
set SERVERPATH=%TOOLSPATH%..\

call :normalise_server_path "%SERVERPATH%"

set PAWNCC=%TOOLSPATH%pawn\pawncc.exe

java -jar %TOOLSPATH%includesupdater\target\includesupdater.jar

%PAWNCC% %SERVERPATH%gamemodes\grgserver.pwn -i%SERVERPATH%includes -; -(

%PAWNCC% %SERVERPATH%npcmodes\npcplayer.pwn -i%SERVERPATH%includes -; -(

:normalise_server_path
SET "SERVERPATH=%~f1"
GOTO :EOF