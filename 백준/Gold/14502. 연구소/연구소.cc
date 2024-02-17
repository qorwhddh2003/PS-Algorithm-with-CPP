#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[8][8], visited[8][8];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus, wall;

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[ny][nx] || a[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

void count(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    ret = max(ret, cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) virus.push_back({i, j});
            else if(a[i][j] == 0) wall.push_back({i, j});
        }
    }
    
    for(int i = 0; i < wall.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                for(pair<int, int> it : virus){
                    dfs(it.first, it.second);
                }
                count();
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }
    cout << ret;    
    return 0;
}