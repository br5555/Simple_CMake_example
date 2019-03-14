#!/bin/sh

cd build
make install
make test

ctest

#To build binary distribution (Mana što napravi sve u binary dir pogledat u terminal sto je napravio i odlucit se za samo jednu opciju ili binary ili source jer jedna drugu prebrikaju)
cpack -C CPackConfig.cmake

#to create a source distribution 
cpack -C CPackSourceConfig.cmake

ctest -D Experimental


