@echo off

set TOOLSPATH=%~dp0
set SERVERPATH=%TOOLSPATH%..\

call :normalise_server_path "%SERVERPATH%"

set PAWNCC=%TOOLSPATH%pawn\pawncc.exe

python %TOOLSPATH%update-command-list.py
python %TOOLSPATH%update-includes.py

%PAWNCC% %SERVERPATH%gamemodes\grgserver.pwn -i%SERVERPATH%includes -; -(

%PAWNCC% %SERVERPATH%npcmodes\npcplayer.pwn -i%SERVERPATH%includes -; -(

:normalise_server_path
SET "SERVERPATH=%~f1"
GOTO :EOF