#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7; 
int main()
{
    long acc_mul(int n);
    bool isPrime(int n);
    int n;
    cin >> n;
    int nums = 0;
    
    for (int i=1; i<n+1; i++){
        if (isPrime(i)==true){
            nums ++;
        }
    }
    cout << acc_mul(nums) * acc_mul(n-nums) % MOD << endl;
    return acc_mul(nums) * acc_mul(n-nums);            
        
    }

long acc_mul(int n){
    long ans = 1;
    for (int i=1; i<n+1; i++){
    ans = ans * i;
    ans = ans % MOD;
    }
    return ans;
}

bool isPrime(int n){
    if(n==1){
        return false;
    }
    else{
        for(int i=2; i*i<=n;i++){
            if (n%i==0){
                return false;
            }
        }
    }
    return true;
}