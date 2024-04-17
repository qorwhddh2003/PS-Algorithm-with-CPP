#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
int N, y, x, d, g, ret;
int visited[101][101];
vector<int> dragon[4][11];

void makeDragon(){
    for(int i = 0; i < 4; i++){
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i + 1) % 4);
        for(int j = 2; j <= 10; j++){
            int size = dragon[i][j - 1].size();
            for(int k = size - 1; k >= 0; k--){
                dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            }
            for(int k = 0; k < size; k++){
                dragon[i][j].push_back(dragon[i][j - 1][k]);
            }
        }
    }
    return;
}

void go(int x, int y, int d, int g){
    visited[x][y] = 1;
    for(int i = 0; i <= g; i++){
        for(int dir : dragon[d][i]){
            y += dy[dir];
            x += dx[dir];
            visited[x][y] = 1;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    makeDragon();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) ret++;
        }
    }
    cout << ret;
    return 0;
}