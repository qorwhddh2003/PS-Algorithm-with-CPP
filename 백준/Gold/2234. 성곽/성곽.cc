#include <bits/stdc++.h>
using namespace std;
#define MAX 50

const int dy[4] = {0, -1, 0, 1}, dx[4] = {-1, 0, 1, 0};
int N, M;
int ret[3], visited[MAX][MAX], a[MAX][MAX], comp[MAX * MAX + 1];

int go(int y, int x, int cnt){
    visited[y][x] = cnt;
    int ret = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if((a[y][x] & (1 << i)) || visited[ny][nx]) continue;
        ret += go(ny, nx, cnt);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;
            ret[0]++;
            comp[ret[0]] = go(i, j, ret[0]);
            ret[1] = max(ret[1], comp[ret[0]]);
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(j + 1 < M){
                int first = visited[i][j], second = visited[i][j + 1];
                if(first != second){
                    ret[2] = max(ret[2], comp[first] + comp[second]);
                }
            }
            if(i + 1 < N){
                int first = visited[i][j], second = visited[i + 1][j];
                if(first != second){
                    ret[2] = max(ret[2], comp[first] + comp[second]);
                }
            }
        }
    }
    
    for(int i = 0; i < 3; i++) cout << ret[i] << "\n";
    return 0;
}