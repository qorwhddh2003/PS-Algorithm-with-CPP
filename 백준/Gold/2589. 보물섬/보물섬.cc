#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, ret;
int visited[50][50];
char a[50][50];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
string s;

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
            
            if(ny <0 || nx < 0 || ny >= N || nx >= M) continue;
            if(a[ny][nx] == 'W' || visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
            cnt = max(cnt, visited[ny][nx]);
        }
    }
    return cnt-1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            a[i][j] = s[j];
        }
    }
    
    for(int i =0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 'L'){
                fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
                ret = max(ret, bfs(i, j));
            }
        }
    }
    cout << ret;
    return 0;
}