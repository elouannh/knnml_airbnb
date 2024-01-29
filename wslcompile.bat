@echo off

set PYTHONSOURCE=setup/csv_generator.py
set SOURCES=main.c src/csv_manager.c

set EXECUTABLE=program.exe

for /f %%i in ("%~dp0") do set "CURDIR=%%~fi"

set "WSLPATH=%CURDIR:\=/%"

set "WSLPATH=%WSLPATH:~0,-1%"

set "WSLPATH=/mnt/c%WSLPATH:~2%"

wsl python3 %WSLPATH%/%PYTHONSOURCE%
wsl gcc %WSLPATH%/%SOURCES% -o %WSLPATH%/%EXECUTABLE%

if %errorlevel% equ 0 (
    echo Compilation succeeded. The executable is named %EXECUTABLE%.

    echo Running the program...
    for /L %%i in (1,1,3) do (echo .)

    wsl %WSLPATH%/%EXECUTABLE%
) else (
    echo Compilation failed.
)