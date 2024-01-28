 #include <bits/stdc++.h>
using namespace std;

const int max_n = 101;
int n, ret;
int a[max_n][max_n], visited[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int height){
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(!visited[ny][nx] && a[ny][nx] > height) dfs(ny, nx, height);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    for(int h = 0; h < 101; h++){
        int cnt = 0;
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && a[i][j] > h){
                    dfs(i, j, h);   
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
    return 0;
}
