#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int n, l, temp, ret;
int board[MAX][MAX], rotated_board[MAX][MAX];

void go(int a[][MAX]){
    for(int i = 0; i < n; i++){
        int cnt = 1, j = 0;
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1]) cnt++;
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
            else if(a[i][j] == a[i][j + 1] + 1 && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(cnt >= 0 && j == n - 1) ret++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> temp;
            board[i][j] = rotated_board[j][i] = temp;
        }
    }
    go(board);
    go(rotated_board);
    cout << ret;
    return 0;
}