#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
int ji_visited[1000][1000], f_visited[1000][1000];
char a[1000][1000];
string s;
pair<int, int> ji_hoon;
vector<pair<int, int>> fire;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void fire_bfs(vector<pair<int, int>> v){
    fill(&f_visited[0][0], &f_visited[0][0] + 1000 * 1000, 1e6);
    queue<pair<int, int>> q;
    for(auto i : v){
        q.push({i.first, i.second});
        f_visited[i.first][i.second] = 1;
    }
    
    int y = 0, x = 0;
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(f_visited[ny][nx] != 1e6 || a[ny][nx] == '#') continue;
            q.push({ny, nx});
            f_visited[ny][nx] = f_visited[y][x] + 1;
        }
    }
}

int bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    ji_visited[y][x] = 1;
    
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        
        if(y == r-1 || x == c-1 || y == 0 || x == 0){
            return ji_visited[y][x];
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ji_visited[ny][nx] || a[ny][nx] == '#') continue;
            if(ji_visited[y][x] + 1 < f_visited[ny][nx]){
                ji_visited[ny][nx] = ji_visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'J') ji_hoon = {i, j};
            else if(a[i][j] == 'F') fire.push_back({i, j});
        }
    }
    
    fire_bfs(fire);
    ret = bfs(ji_hoon.first, ji_hoon.second);
    if(ret == -1) cout << "IMPOSSIBLE";
    else cout << ret;
    return 0;
}