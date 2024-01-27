#include <bits/stdc++.h>
using namespace std;
const int max_n = 101;
int n, m, sy, sx, y, x;
int a[max_n][max_n], visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    sy = 0; sx = 0;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    while(q.size()){
        tie(y, x) = q.front(); 
        q.pop();
        
        if(y == n-1 && x == m-1) break;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny > n-1 || nx > m-1 || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    
    cout << visited[n-1][m-1];
    
    return 0;
}