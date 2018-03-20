#/bin/bash

cd argobots
ls
make clean
make -j40
make install
cd -
cd build-abt
ls
make -j40
make install
cd -
