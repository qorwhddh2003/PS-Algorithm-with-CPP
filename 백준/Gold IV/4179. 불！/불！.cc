#include <bits/stdc++.h>
using namespace std;

int r, c, x, y, sx, sy, ret=-1;
string s;
int fire_visited[1000][1000], visited[1000][1000];
char a[1000][1000];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> fq, q;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            a[i][j] = s[j];
        }
    }
    
    fill(&fire_visited[0][0], &fire_visited[0][0] + 1000 * 1000, 1e6);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] == 'F') {
                fq.push({i, j});
                fire_visited[i][j] = 1;
            }
            else if(a[i][j] == 'J') sy = i, sx = j;
        }
    }
    
    while(fq.size()){
        tie(y, x) = fq.front();
        fq.pop();
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(fire_visited[ny][nx] != 1e6 || a[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            fq.push({ny, nx});
        }
    }
    
    q = queue<pair<int, int>>();
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        
        if(y == 0 || x == 0 || y == r - 1 || x == c - 1){
            ret = visited[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx] || a[ny][nx] == '#') continue;
            if(fire_visited[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret==-1) cout << "IMPOSSIBLE";
    else cout << ret;
    return 0;
}