#include <bits/stdc++.h>
using namespace std;

const int INF = 9e8;
int N, M, H, a, b, ret = INF;
int visited[34][14];

bool check(){
    for(int i = 1; i <= N; i++){
        int start = i;
        for(int j = 1; j <= H; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start - 1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

void ladder(int here, int count){
    if(count > 3 || count >= ret) return;
    if(check()){
        ret = min(ret, count);  
        return;
    } 
    for(int i = here; i <= H; i++){
        for(int j = 1; j < N; j++){
            if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            ladder(i, count + 1);
            visited[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        visited[a][b] = 1;
    }
    
    ladder(1, 0);
    cout << (ret == INF ? -1 : ret);
    return 0;
}