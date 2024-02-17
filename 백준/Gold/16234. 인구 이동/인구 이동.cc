#include <bits/stdc++.h>
using namespace std;

int n, l, r, ret;
bool flag = 0;
int a[50][50], visited[50][50];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            dfs(ny, nx, v);
            v.push_back({ny, nx});
        }
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    while(true){
        flag = 0;
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]) continue;
                v.clear();
                v.push_back({i, j});
                dfs(i, j, v);
                int sum = 0;
                int vSize = v.size();
                if(vSize == 1) continue;
                for(auto it : v){
                    sum += a[it.first][it.second];
                }
                sum /= vSize;
                for(auto it : v){
                    a[it.first][it.second] = sum;
                }
                flag = 1;
            }
        }
        if(flag == 0) break;
        ret++;
    }
    
    cout << ret;
    return 0;
}