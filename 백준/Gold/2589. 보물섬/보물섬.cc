#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int visited[54][54];
char a[54][54];
string s;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int bfs(int y, int x){
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] || a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            cnt = max(cnt, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return cnt - 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L'){
                fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                ret = max(ret, bfs(i, j));
            }
        }
    }
    cout << ret;
    return 0;
}