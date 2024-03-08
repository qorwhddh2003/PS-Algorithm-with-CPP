#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 9e8;
char a[51][51];

int checkBoard(int y, int x, char bw){
    int cnt = 0;
    for(int i = y; i < y + 8; i++){
        for(int j = x; j < x + 8; j++){
            if((i + j) % 2 == 0 && a[i][j] == bw) cnt++;
            else if((i + j) % 2 != 0 && a[i][j] != bw) cnt++;
        }
    }
    return 64 - cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            ret = min(ret, checkBoard(i, j, 'W'));
            ret = min(ret, checkBoard(i, j, 'B'));
        }
    }
    cout << ret;
    return 0;
}
