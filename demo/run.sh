rm -rf ./build
rm ./project_2
mkdir build
cd build
cmake ..
make
cp project_2 ../
cd ..
./project_2