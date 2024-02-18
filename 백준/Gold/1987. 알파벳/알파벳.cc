#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
string s;
char a[20][20];
int visited_word[26];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void go(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if(visited_word[a[ny][nx] - 'A']) continue;
        visited_word[a[ny][nx] - 'A'] = 1;
        go(ny, nx, cnt + 1);
        visited_word[a[ny][nx] - 'A'] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> s;
        for(int j = 0; j < c; j++){
            a[i][j] = s[j];
        }
    }
    visited_word[a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret;
    return 0;
}