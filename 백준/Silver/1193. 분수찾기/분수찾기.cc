#include <bits/stdc++.h>
using namespace std;

int n, k = 1; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(true){
        if(k * (k - 1) / 2 < n && n <= k * (k + 1) / 2) break;
        k++;
    }
    
    int a = k * (k + 1) / 2 - n;
    if(k % 2){
        cout << 1 + a << "/" <<  k - a;
    }else{
        cout << k - a << "/" << 1 + a;
    }
    return 0;
}