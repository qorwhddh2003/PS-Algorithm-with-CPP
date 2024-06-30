#include <bits/stdc++.h>
using namespace std;
#define MAX_N 17
int N, ret;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][3];

bool check(int y, int x, int dir){
    if(dir == 0 || dir == 1){
        if(!a[y][x]) return true;
    }else if(dir == 2){
        if(a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }
    dp[1][2][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][0];
            
            if(check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][1];
            if(check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][1];
            
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][2];
            if(check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][2];
            if(check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][2];
        }
    }
    
    for(int i = 0; i < 3; i++){
        ret += dp[N][N][i];
    }
    cout << ret;
    return 0;
}

// 가로 -> 가로, 대각선
// 세로 -> 세로, 대각선
// 대각선 -> 가로, 세로, 대각선