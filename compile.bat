@echo off

set PYTHONSOURCE=setup/csv_generator.py
set SOURCES=main.c src/csv_manager.c

set EXECUTABLE=program.exe

python %PYTHONSOURCE%
gcc -mconsole %SOURCES% -o %EXECUTABLE%

if %errorlevel% equ 0 (
    echo Compilation succeeded. The executable is named %EXECUTABLE%.

    echo Running the program...
    .\%EXECUTABLE%
) else (
    echo Compilation failed.
)