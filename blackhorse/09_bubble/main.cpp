#include <iostream>

using namespace std;

void bubble (int * arr)
{
    int l = 10;
    for (int i = 0; i < l-1; i++)
    {
        for (int j = 0; j < l-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main ()
{
    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    bubble(arr);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}