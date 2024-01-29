@echo off

set PYTHONSOURCE=setup/csv_generator.py
set SOURCES=main.c src/csv_manager.c

set EXECUTABLE=program.exe

python %PYTHONSOURCE%
gcc -mconsole %SOURCES% -o %EXECUTABLE%

if %errorlevel% equ 0 (
    echo Compilation succeeded. The executable is named %EXECUTABLE%.

    echo Running the program...
    for /L %%i in (1,1,3) do (echo .)

    .\%EXECUTABLE%
) else (
    echo Compilation failed.
)