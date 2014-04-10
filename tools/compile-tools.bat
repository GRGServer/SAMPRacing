@echo off

set TOOLSPATH=%~dp0
set MAVEN=%TOOLSPATH%apache-maven\bin\mvn.bat

call %MAVEN% -f %TOOLSPATH%includesupdater clean package
call %MAVEN% -f %TOOLSPATH%todofinder clean package