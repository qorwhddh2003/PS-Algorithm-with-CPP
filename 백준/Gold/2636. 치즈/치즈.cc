#include <bits/stdc++.h>
using namespace std;

int N, M, ret, h;
int a[100][100], visited[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;

int bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        visited[y][x] = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            if(a[ny][nx] == 1) v.push_back({ny, nx});
            else q.push({ny, nx});
        }
    }
    for(auto it : v) a[it.first][it.second] = 0;
    return v.size();
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    
    while(true){
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
        v.clear();
        if(bfs(0, 0)){
            ret = v.size();
            h++;
        }
        else break;
    }
   
    cout << h << "\n" << ret;
    return 0;
}
