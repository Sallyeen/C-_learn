rm -rf build
mkdir build
cd build
cmake ..
make
cp encrypt ../
cp decrypt ../
cd ..

./encrypt ./code_book.txt ./data_in.txt ./en_code.txt
./decrypt ./code_book.txt ./en_code.txt ./de_code.txt
