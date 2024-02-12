#include <bits/stdc++.h>
using namespace std;

int N, L, R, day, sum, cnt;
int a[50][50], visited[50][50];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, vector<pair<int, int>> &v){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= L && abs(a[ny][nx] - a[y][x]) <= R){
            sum += a[ny][nx];
            v.push_back({ny, nx});
            dfs(ny, nx, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    
    while(true){
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j]) continue;
                vector<pair<int, int>> v;
                v.push_back({i, j});
                sum = a[i][j];
                dfs(i, j, v);
                if(v.size() == 1) continue;
                for(pair<int, int> it : v){
                    a[it.first][it.second] = sum / v.size();
                    flag = 1;
                }
            }
        }
        if(!flag) break;
        day++;
    }
    
    cout << day;
    return 0;
}