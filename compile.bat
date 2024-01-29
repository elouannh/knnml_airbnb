@echo off

set EXECUTABLE=program.exe

set SOURCES=main.c src/csv_manager.c

gcc -mconsole %SOURCES% -o %EXECUTABLE%

if %errorlevel% equ 0 (
    echo Compilation succeeded. The executable is named %EXECUTABLE%.

    echo Running the program...
    .\%EXECUTABLE%
) else (
    echo Compilation failed.
)