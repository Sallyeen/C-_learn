rm -rf build
mkdir build
cd build
cmake ..
make
cp demo ../
cd ..
./demo