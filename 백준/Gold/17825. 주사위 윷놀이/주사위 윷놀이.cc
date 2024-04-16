#include <bits/stdc++.h>
using namespace std;

int ret;
vector<int> v[33];
int dice[10], visited[33], score[33] = {
    0, 2, 4, 6, 8, 
    10, 12, 14, 16, 18, 
    20, 22, 24, 26, 28, 
    30, 32, 34, 36, 38, 
    40, 13, 16, 19, 22, 
    24, 28, 27, 26, 25, 
    30, 35, -1
};

void addVector(int here, int there){
    v[here].push_back(there);
}

int move(int here, int there, int cnt){
    while(cnt){
        here = there;
        if(score[here] == -1) return here;
        there = v[here][0];
        cnt--;
    }
    return here;
}

void go(int idx, int pos[4], int sum, int used){
    if(idx == 10){
        ret = max(ret, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        if(used & (1 << i)) continue;
        int here = pos[i];
        int there = move(here, v[here][(v[here].size() + 1) % 2], dice[idx]);
        if(there != 32 && visited[there]) continue;
        pos[i] = there;
        visited[here] = 0;
        visited[there] = 1;
        go(idx + 1, pos, sum + max(score[there], 0), (there == 32 ? used | (1 << i) : used));
        pos[i] = here;
        visited[here] = 1;
        visited[there] = 0;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 10; i++) cin >> dice[i];
    for(int i = 0; i <= 19; i++) addVector(i, i + 1); 
    addVector(5, 21); addVector(21, 22); addVector(22, 23); addVector(23, 29);
    addVector(10, 24); addVector(24, 25); addVector(25, 29);
    addVector(15, 26); addVector(26, 27); addVector(27, 28); addVector(28, 29);
    addVector(29, 30); addVector(30, 31); addVector(31, 20); addVector(20, 32);
    int pos[4] = {dice[0], 0, 0, 0};
    go(1, pos, score[dice[0]], 0);
    cout << ret;
    return 0;
}
