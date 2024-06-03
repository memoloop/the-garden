#!/bin/bash

# Compile
g++ \
    src/*.cpp \
    src/game/*.cpp \
    src/game/plant/*.cpp \
    src/game/scenes/*.cpp \
    src/game/forms/*.cpp \
    src/components/*.cpp \
    src/components/gui/*.cpp \
    \
    -lSDL2 \
    -lSDL2_image \
    -lSDL2_ttf \
    \
    -o game

# Run
./game
