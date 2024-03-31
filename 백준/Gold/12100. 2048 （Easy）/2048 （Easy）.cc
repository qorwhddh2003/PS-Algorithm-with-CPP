#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int ret, N;
struct Board{
    int a[MAX][MAX];
    void rotate90(){
        int temp[MAX][MAX];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                temp[i][j] = a[N - j - 1][i];
            }
        }
        memcpy(a, temp, sizeof(a));
    }
    
    void move(){
        int temp[MAX][MAX];
        for(int i = 0; i < N; i++){ 
            int cur = -1, flag = 0;
            for(int j = 0; j < N; j++){
                if(a[i][j] == 0) continue;
                if(flag && a[i][j] == temp[i][cur]) temp[i][cur] *= 2, flag = 0;
                else temp[i][++cur] = a[i][j], flag = 1;
            }
            for(int c = cur + 1; c < N; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }
    
    void getMax(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ret = max(ret, a[i][j]);
            }
        }
    }
};

void go(Board board, int cnt){
    if(cnt == 5){
        board.getMax();
        return;
    }
    
    for(int i = 0; i < 4; i++){
        Board copy_board = board;
        copy_board.move();
        go(copy_board, cnt + 1);
        board.rotate90();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    Board board;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board.a[i][j];
        }
    }
    go(board, 0);
    cout << ret;
    return 0;
}