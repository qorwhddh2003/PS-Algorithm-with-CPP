#include <bits/stdc++.h>
using namespace std;
#define MAX 8

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int N, M, y, x, ret = 9e8;
int a[MAX][MAX], visited[MAX][MAX];
vector<pair<int, int>> cctv;
vector<vector<int>> dir_array[6];

int count(int visited[MAX][MAX]){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] || a[i][j]) continue;
            cnt++;
        }
    }
    return cnt;
}

void go(int here, int visited[MAX][MAX]){
    if(here == cctv.size()){
        ret = min(ret, count(visited));
        return;
    }
    
    int temp_visited[MAX][MAX];
    memcpy(temp_visited, visited, sizeof(temp_visited));
    int num = a[cctv[here].first][cctv[here].second];
    for(int dir : dir_array[num][0]){
        for(int i = 0; i < 4; i++){
            y = cctv[here].first, x = cctv[here].second;
            if(dir & (1 << i)){
                while(true){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny < 0 || nx < 0 || ny >= N || nx >= M || a[ny][nx] == 6) break;
                    temp_visited[ny][nx] = 1;
                    y = ny, x = nx;
                }
            }
        }
        go(here + 1, temp_visited);
        memcpy(temp_visited, visited, sizeof(temp_visited));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dir_array[1].push_back({1, 2, 4, 8});
    dir_array[2].push_back({5, 10});
    dir_array[3].push_back({3, 6, 12, 9});
    dir_array[4].push_back({7, 14, 13, 11});
    dir_array[5].push_back({15});
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
            if(a[i][j] > 0 && a[i][j] < 6){
                cctv.push_back({i, j});
            }
        }
    }
    
    go(0, visited);
    cout << ret;
    return 0;
}
