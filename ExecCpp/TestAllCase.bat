@echo off

cd /d %~dp0

set CONTESTNAME=%1
set PROBLEM=%2
set CONFIGURATION=%3

@rem call :test %CONTESTNAME% %PROBLEM% 1
@rem call :test %CONTESTNAME% %PROBLEM% 2
@rem call :test %CONTESTNAME% %PROBLEM% 3

@rem exit /b 0

"%~dp0%CONFIGURATION%\ExecCpp.exe" < "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-1.in"
type "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-1.out"
"%~dp0%CONFIGURATION%\ExecCpp.exe" < "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-2.in"
type "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-2.out"
"%~dp0%CONFIGURATION%\ExecCpp.exe" < "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-3.in"
type "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-3.out"
"%~dp0%CONFIGURATION%\ExecCpp.exe" < "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-4.in"
type "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-4.out"
"%~dp0%CONFIGURATION%\ExecCpp.exe" < "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-5.in"
type "%~dp0%CONTESTNAME%\%PROBLEM%\tests\sample-5.out"
