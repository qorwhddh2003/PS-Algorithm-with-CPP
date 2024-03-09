#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n > 0){
        if(n & 1) ret++;
        n /= 2;
    }
    cout << ret;
    return 0;
}
