#include <bits/stdc++.h>
using namespace std;

int n, cnt = 2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cnt += cnt - 1;
    }
    cout << cnt * cnt;
    return 0;
}