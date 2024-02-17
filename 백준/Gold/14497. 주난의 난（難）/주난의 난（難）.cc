#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

int n, m, x1, y1, x2, y2;
int visited[300][300];
char a[301][301];
string s;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int main()
{
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;
    
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    
    queue<int> q;
    q.push(y1 * 1000 + x1);
    visited[y1][x1] = 1;
    int cnt = 0;
    while(a[y2][x2] != '0'){
        cnt++;
        queue<int> temp;
        while(q.size()){
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }else q.push(1000 * ny + nx);
            }
        }
        q = temp;
    }
    cout << visited[y2][x2];
    return 0;
}