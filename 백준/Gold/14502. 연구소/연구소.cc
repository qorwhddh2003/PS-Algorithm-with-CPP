#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int a[8][8], visited[8][8];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus_list, wall_list;
void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx] || a[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
    return;
}

int solve(){
    fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
    for(auto it : virus_list){
        if(visited[it.first][it.second]) continue;
        dfs(it.first, it.second);
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];   
            if(a[i][j] == 2) virus_list.push_back({i, j});
            else if(a[i][j] == 0)  wall_list.push_back({i, j});
        }
    }

    for(int i = 0; i < wall_list.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                a[wall_list[i].first][wall_list[i].second] = 1;
                a[wall_list[j].first][wall_list[j].second] = 1;
                a[wall_list[k].first][wall_list[k].second] = 1;
                ret = max(ret, solve());
                a[wall_list[i].first][wall_list[i].second] = 0;
                a[wall_list[j].first][wall_list[j].second] = 0;
                a[wall_list[k].first][wall_list[k].second] = 0;
            }
        }
    }
    cout << ret;
    return 0;
}
