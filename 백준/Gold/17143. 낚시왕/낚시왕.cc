#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, 1, -1};
int R, C, M, angler, ret;
int a[MAX][MAX], temp_arr[MAX][MAX], death[MAX * MAX];
struct Shark{
    int r, c, s, d, z;
} shk[MAX * MAX];

void catchShark(int pos){
    for(int i = 0; i < R; i++){
        if(a[i][pos]){
            ret += shk[a[i][pos] - 1].z;
            death[a[i][pos] - 1] = 1;
            return;
        }
    }
}

void move(){
    fill(&temp_arr[0][0], &temp_arr[0][0] + MAX * MAX, 0);
    for(int i = 0; i < M; i++){
        if(death[i]) continue;
        Shark * shark = &shk[i];
        int t = shark->s;
        while(t){
            int ny = shark->r + dy[shark->d];
            int nx = shark->c + dx[shark->d];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C){
                shark->d = (shark->d + 1) % 2 + (shark->d >= 2 ? 2 : 0);
                continue;
            }
            shark->r = ny;
            shark->c = nx;
            t--;
        }
        
        int temp = temp_arr[shark->r][shark->c];
        if(temp){
            if(shk[temp - 1].z > shark->z){
                death[i] = 1;
            }else{
                temp_arr[shark->r][shark->c] = i + 1;
                death[temp - 1] = 1;
            }
        }else{
            temp_arr[shark->r][shark->c] = i + 1;
        }
    }
    memcpy(a, temp_arr, sizeof(a));
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++){
        cin >> shk[i].r >> shk[i].c >> shk[i].s >> shk[i].d >> shk[i].z;
        shk[i].r--, shk[i].c--, shk[i].d--;
        a[shk[i].r][shk[i].c] = i + 1;
        
        if(shk[i].d < 2) shk[i].s %= (R - 1) * 2;
        else shk[i].s %= (C - 1) * 2;
    }
    
    while(angler < C){
        catchShark(angler);
        move();
        angler++;
    }
    cout << ret;
    return 0;
}