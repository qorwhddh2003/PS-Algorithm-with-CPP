#include <bits/stdc++.h>
using namespace std;

string s;
char a[1501][1501];
int n, m, y, x, swanX, swanY, day;
int visited[1501][1501], swan_visited[1501][1501];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> swanQ, swan_tempQ, waterQ, water_tempQ;

void Qclear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void WaterMelting(queue<pair<int, int>> &q){
    while(waterQ.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if(a[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                water_tempQ.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

bool MoveSwan(queue<pair<int, int>> &q){
    while(swanQ.size()){
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || swan_visited[ny][nx]) continue;
            swan_visited[ny][nx] = 1;
            if(a[ny][nx] == '.') swanQ.push({ny, nx});
            else if(a[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L') {swanY = i; swanX = j;}
            if(a[i][j] == '.' || a[i][j] == 'L'){
                waterQ.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    
    swanQ.push({swanY, swanX});
    swan_visited[swanY][swanX] = 1;
    while(true){
        if(MoveSwan(swanQ)) break;
        WaterMelting(waterQ);
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }
    cout << day;
    return 0;
}