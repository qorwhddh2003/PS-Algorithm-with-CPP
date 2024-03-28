#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int R, C, T, ret;
int room[MAX][MAX], visited[MAX][MAX];
pair<int, int> cleaner;

void diffusion(int room[MAX][MAX]){
    int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(room[i][j] > 0){
                int moved_dust = room[i][j] / 5;
                for(int k = 0; k < 4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                    if(room[ny][nx] == -1) continue;
                    visited[ny][nx] += moved_dust;
                    room[i][j] -= moved_dust;
                }
            }
        }
    }
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            room[i][j] += visited[i][j];
        }
    }
}

void cleanerOn(int board[MAX][MAX]){
    int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
    int y = cleaner.first - 1, x = cleaner.second + 1;
    int idx = 0, prev = board[y][x];
    
    board[y][x] = 0;
    while(true){
        int ny = y + dy[idx], nx = x + dx[idx];
        if(ny < 0 || nx < 0 || ny >= cleaner.first || nx >= C){
            idx++;
            continue;
        }
        if(board[ny][nx] == -1) break;
        int temp = board[ny][nx];
        board[ny][nx] = prev;
        prev = temp;
        y = ny, x = nx;
    }
    
    int dy2[4] = {0, 1, 0, -1}, dx2[4] = {1, 0, -1, 0};
    y = cleaner.first, x = cleaner.second + 1;
    idx = 0, prev = board[y][x];
    
    board[y][x] = 0;
    while(true){
        int ny = y + dy2[idx], nx = x + dx2[idx];
        if(ny < cleaner.first || nx < 0 || ny >= R || nx >= C){
            idx++;
            continue;
        }
        if(board[ny][nx] == -1) break;
        int temp = board[ny][nx];
        board[ny][nx] = prev;
        prev = temp;
        y = ny, x = nx;
    }
}

int main(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> room[i][j];
            if(room[i][j] == -1) cleaner = {i, j};
        }
    }
    
    while(T--){
        diffusion(room);
        cleanerOn(room);
    }
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(room[i][j] != -1) ret += room[i][j];
        }
    }
    cout << ret;
    return 0;
}