#include <bits/stdc++.h>
using namespace std;
#define y1 aaaaa

int n, m, x1, y1, x2, y2, ret, yy, xx;
bool flag = 0;
char a[300][300];
int visited[300][300];
string s;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void bfs(int y, int x){
    queue<pair<int, int>> q;
    queue<pair<int, int>> qq;
    q.push({y, x});
    visited[y][x] = 1;
    
    while(q.size()){
        tie(y, x) = q.front();
        q.pop();
        
        if(y == y2 - 1 && x == x2 - 1){
            ret = visited[y][x] - 1;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == '0'){
                visited[ny][nx] = visited[y][x];
                qq.push({ny, nx});
            }
            else{
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        while(qq.size()){
            tie(yy, xx) = qq.front();
            qq.pop();
            
            if(yy == y2 - 1 && xx == x2 - 1){
                flag = 1;
                ret = visited[yy][xx];
                break;
            }
            
            for(int i = 0; i < 4; i++){
                int nny = yy + dy[i];
                int nnx = xx + dx[i];
                if(nny < 0 || nnx < 0 || nny >= n || nnx >= m || visited[nny][nnx]) continue;
                if(a[nny][nnx] == '0' || a[nny][nnx] == '#'){
                    visited[nny][nnx] = visited[y][x];
                    qq.push({nny, nnx});
                }else{
                    visited[nny][nnx] = visited[y][x] + 1;
                    q.push({nny, nnx});
                }
            }
        }
        if(flag) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    bfs(y1 - 1, x1 - 1);
    cout << ret;
    return 0;
}