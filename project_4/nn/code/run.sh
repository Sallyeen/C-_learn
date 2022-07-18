rm -rf build
rm project_4
mkdir build
cd build
cmake ..
make 
cp project_4 ../
cd ..
./project_4