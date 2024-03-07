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
        cout << a + 1 << "/" << k - a;
    }else{
        cout << k - a << "/" << a + 1;
    }
    return 0;
}
