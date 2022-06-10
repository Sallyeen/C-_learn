rm -rf build
mkdir build
cd build
cmake ..
make
cp encrypt ../
cp decrypt ../
cd ..

# ./encrypt ./code_book.txt ./data_in.txt ./en_code.txt
# ./decrypt ./code_book.txt ./en_code.txt ./de_code.txt

./encrypt ./code_book.txt ./lena.jpg ./en_lena.jpg
./decrypt ./code_book.txt ./en_lena.jpg ./de_lena.jpg

#./encrypt ./code_book.txt ./a.out ./en_a_out
#./decrypt ./code_book.txt ./en_a_out ./de_a_out
