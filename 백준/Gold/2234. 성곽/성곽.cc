#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
const int dy[4] = {0, -1 , 0, 1}, dx[4] = {-1, 0, 1, 0};
int n, m;
int a[MAX+1][MAX+1], conneted_comp[2504], visited[MAX+1][MAX+1];

int dfs(int y, int x, int cnt){
    visited[y][x] = cnt;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if(a[y][x] & (1 << i)) continue;
        ret += dfs(ny, nx, cnt);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    int cnt = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            conneted_comp[cnt] = dfs(i, j, cnt);
            cnt++;
        }
    }
    
    int mx = 0, remove_wall = 0;
    for(int i = 0; i < cnt; i++) mx = max(mx, conneted_comp[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if(a[i][j] << (1 << k)){
                    if(visited[i][j] != visited[ny][nx]){
                        remove_wall = max(remove_wall, conneted_comp[visited[i][j]] + conneted_comp[visited[ny][nx]]);
                    }
                }
            }
        }
    }
    
    cout << cnt-1 << "\n" << mx << "\n" << remove_wall;
    return 0;
}
