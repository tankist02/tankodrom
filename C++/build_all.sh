#!/bin/sh

BUILD_TYPE=debug make -j `nproc` `ls *.cpp | sed 's/\.cpp$//g'`

