#/bin/bash

cd argobots
./autogen.sh
mkdir argobots
./configure --prefix=$PWD/argobots 
make clean
make -j40
make install
cd -

mkdir bolt 
mkdir build-abt
source env.sh
cd build-abt
cmake ../llvm -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=../bolt -DLIBOMP_USE_ARGOBOTS=on -DLIBOMP_ARGOBOTS_INSTALL_DIR=../argobots/argobots -DLIBOMP_USE_ITT_NOTIFY=off
make -j40
make install
cd -
