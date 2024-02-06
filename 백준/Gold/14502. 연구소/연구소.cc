#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 0;
int a[8][8], visited[8][8];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> wall, virus;

void SafetyArea(){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    ret = max(ret, cnt);
    return;
}

void DiffusionVirus(int y, int x){
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || a[ny][nx] == 1) continue;
        DiffusionVirus(ny, nx);
    }
    return;
}

void CreateWall(int start, vector<pair<int, int>> b){
    if(b.size() == 3){
        fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
        for(auto it : b) a[it.first][it.second] = 1;
        for(auto it : virus) DiffusionVirus(it.first, it.second);
        SafetyArea();
        for(auto it : b) a[it.first][it.second] = 0;
        return;
    }
    for(int i = start + 1; i < wall.size(); i++){
        b.push_back(wall[i]);
        CreateWall(i, b);
        b.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) wall.push_back({i, j});
            else if(a[i][j] == 2) virus.push_back({i, j});
        }
    }
    
    vector<pair<int, int>> b;
    CreateWall(-1, b);
    cout << ret;
        
    return 0;
}