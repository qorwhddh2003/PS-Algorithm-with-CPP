#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;
int t, n, m, k, cy, cx, y, x;
int a[max_n][max_n], visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        
        int ret = 0;
        queue<pair<int, int>> cabbage_loc;
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < k; i++){
            cin >> cy >> cx;
            a[cy][cx] = 1;
            cabbage_loc.push({cy, cx});
        }
        
        while(cabbage_loc.size()){
            tie(cy, cx) = cabbage_loc.front();
            cabbage_loc.pop();
            
            if(visited[cy][cx]) continue;
            ret++;
            dfs(cy, cx);
        }
        
        cout << ret << "\n";
    }

    return 0;
}
