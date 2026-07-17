@echo off
cd /d "%~dp0"
echo Build started %date% %time% > build_log.txt
if not exist "C:\raylib\w64devkit\bin\g++.exe" (
    echo ERROR: g++ not found at C:\raylib\w64devkit\bin >> build_log.txt
    goto :end
)
set "PATH=C:\raylib\w64devkit\bin;%PATH%"
g++ src\*.cpp -o build\main.exe -std=c++17 -O2 -I C:\raylib\raylib\src -L C:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm >> build_log.txt 2>&1
if %errorlevel% neq 0 (
    echo BUILD FAILED >> build_log.txt
    goto :end
)
echo BUILD OK >> build_log.txt
start "" "build\main.exe"
:end
