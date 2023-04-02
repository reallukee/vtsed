#!/bin/bash

src="../vtsed/"

#if ! [[ -e "vtsed.so" ]] ; then
#    g++ $src*.cpp -shared -o vtsed.so
#fi

#g++ main.cpp -o main -L. -lvtsed.so

if ! [ -e "*.o" ] ; then
    g++ -c $src*.cpp
fi

g++ main.cpp *.o -o main
