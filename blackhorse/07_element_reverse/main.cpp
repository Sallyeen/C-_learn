#include <iostream>

using namespace std;

int main ()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[5];
    for (int i=0; i<5; i++)
    {
        arr1[i] = arr[4-i];
        cout << arr1[i] << "\t";
    }
    cout << "\n";
}