#include <bits/stdc++.h>
using namespace std;


const int MAX = 50;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int N, M, T, x, d, k, ret;
int a[MAX][MAX], visited[MAX][MAX];
bool flag = true;

void _rotate(int y, int dir, int k){
    vector<int> temp;
    for(int i = 0; i < M; i++) temp.push_back(a[y][i]);
    if(dir == 1) rotate(temp.begin(), temp.begin() + k, temp.end());
    else rotate(temp.begin(), temp.begin() + M - k, temp.end());
    for(int i = 0; i < M; i++) a[y][i] = temp[i];
    return;
}

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = (x + dx[i] + M) % M;
        if(ny < 0 || ny >= N || visited[ny][nx]) continue;
        if(a[y][x] != a[ny][nx]) continue;
        visited[y][x] = visited[ny][nx] = 1;
        flag = false;
        dfs(ny, nx);
    }
}

bool isAct(){
    flag = true;
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0) continue;
            if(visited[i][j]) continue;
            dfs(i, j);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]){
                a[i][j] = 0;
            }
        }
    }
    return flag;
}

void setAverage(){
    double sum = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j]){
                sum += (double)a[i][j];
                cnt++;
            }
        }
    }
    double avg = sum / cnt;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] == 0) continue;
            if(avg < (double)a[i][j]) a[i][j]--;
            else if(avg > (double)a[i][j]) a[i][j]++;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    
    while(T--){
        cin >> x >> d >> k;
        for(int i = x - 1; i < N; i += x){
            _rotate(i, d, k);
        }

        if(isAct()){
            setAverage();
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ret += a[i][j];
        }
    }
    cout << ret;
    return 0;
}
