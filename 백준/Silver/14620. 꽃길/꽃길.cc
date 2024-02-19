#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int n, g, sum, ret = 1e6;
int a[MAX][MAX], visited[MAX][MAX];
int dy[5] = {0, -1, 0, 1, 0}, dx[5] = {0, 0, 1, 0, -1};

bool check(int y, int x){
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return 0;
    }
    return 1;
}

int setFlower(int y, int x){
    int s = 0;
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }
    return s;
}

void resetFlower(int y, int x){
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void go(int sum, int cnt){
    if(cnt == 3){
        ret = min(ret, sum);
        return;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check(i, j)){
                go(sum + setFlower(i, j), cnt + 1);
                resetFlower(i, j);
            }
        }
    }
    

    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j =0 ; j < n; j++){
            cin >> a[i][j];
        }
    }
    go(0, 0);
    cout << ret;
    return 0;
}