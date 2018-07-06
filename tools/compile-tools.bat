@echo off

set TOOLSPATH=%~dp0
set MAVEN=%TOOLSPATH%apache-maven\bin\mvn.bat

call %MAVEN% -f %TOOLSPATH%languagestringeditor clean package