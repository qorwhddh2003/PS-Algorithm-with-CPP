#include <bits/stdc++.h>
using namespace std;

const int max_n = 101;
int m, n, k, y, x, y2, x2, ret, cnt;
int a[max_n][max_n];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> v;

void dfs(int y, int x){
    a[y][x] = 1;
    cnt++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if(a[ny][nx]) continue;
        dfs(ny, nx);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n >> k;
    while(k--){
        cin >> x >> y >> x2 >> y2;
        for(int i = y; i < y2; i++){
            for(int j = x; j < x2; j++){
                a[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0){
                cnt = 0;
                ret++;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    cout << ret << "\n";
    for(int i : v) cout << i << " ";
    
    return 0;
}
