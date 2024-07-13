#include <bits/stdc++.h>
using namespace std;
#define MAX_N 51
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int N, M;
int dp[MAX_N][MAX_N], visited[MAX_N][MAX_N];
char a[MAX_N][MAX_N];

int go(int y, int x){
    if(y < 0 || x < 0 || y >= N || x >= M || a[y][x] == 'H') return 0;
    if(visited[y][x]){
        cout << -1;
        exit(0);
    }
    
    int &ret = dp[y][x];
    if(~ret) return ret;
    
    ret = 0;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + (int)a[y][x] * dy[i];
        int nx = x + (int)a[y][x] * dx[i];
        ret = max(ret, go(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] != 'H') a[i][j] -= '0';
        }
    }
    
    cout << go(0, 0);
    return 0;
} 