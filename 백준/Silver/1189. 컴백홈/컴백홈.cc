#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;
int r, c, k, ret;
char a[MAX+1][MAX+1];
int visited[MAX+1][MAX+1];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void go(int y, int x, int cnt){
    if(cnt == k && y == 0 && x == c-1){
        ret++;
        return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
        }
    }
    
    visited[r - 1][0] = 1;
    go(r - 1, 0, 1);
    cout << ret;
    return 0;
}