#!/bin/bash

INCLUDE='physic.c'
MAIN='main.c'
COMPILER='gcc'
LIBS='-lSDL2'

$COMPILER $MAIN -o file $INCLUDE $LIBS 
