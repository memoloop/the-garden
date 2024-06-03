@echo off

rem compile
g++ ^
    src/*.cpp ^
    src/game/*.cpp ^
    src/game/plant/*.cpp ^
    src/game/scenes/*.cpp ^
    src/game/forms/*.cpp ^
    src/components/*.cpp ^
    src/components/gui/*.cpp ^
    ^
    -I./include ^
    -L. ^
    -lSDL2 ^
    -lSDL2_image ^
    -lSDL2_ttf ^
    ^
    -o game.exe
rem run
game.exe