#include <bits/stdc++.h>
using namespace std;

int n, cnt, st = 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n == 1){cout << 1; return 0;}
    while(true){
        if(st >= n && n <= st + cnt * 6) break;
        st += cnt * 6;
        cnt++;
    }
    cout << cnt;    
    return 0;
}