#include <bits/stdc++.h>
using namespace std;

int n, ret = 987654321;
int a[10][10], visited[10][10];
int dy[5] = {0, -1, 0, 1, 0}, dx[5] = {0, 0, 1, 0, -1};

bool Check(int y, int x){
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false;
    }
    return true;
}

int SetFlower(int y, int x){
    int s = 0;
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }
    return s;
}

void ResetFlower(int y, int x){
    for(int i = 0; i < 5; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void Go(int cnt, int sum){
    if(cnt == 3){
        ret = min(sum, ret);
        return;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Check(i, j)){
                Go(cnt + 1, sum + SetFlower(i, j));
                ResetFlower(i, j);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    Go(0, 0);
    cout << ret;
    return 0;
}