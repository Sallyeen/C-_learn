#include <iostream>

using namespace std;

int main ()
{
    int arr[5] = {300, 350, 200, 400, 250};
    int ans = arr[0];
    for (int i=1; i<5; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    cout << "最终的小猪体重为： " << ans << endl;
}