#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int N, S, ret = 9e8;
int a[MAX][MAX];

int go(vector<int> v){
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            int first = v[i], second = v[j];
            sum += (a[first][second] + a[second][first]);
        }
    }
    return sum;
}

void combi(int start, int cnt, int visited){
    if(cnt == N / 2){
        vector<int> start, link;
        for(int i = 0; i < N; i++){
            if(visited & (1 << i)) start.push_back(i + 1);
            else link.push_back(i + 1);
        }
        ret = min(ret, (abs(go(start) - go(link))));
        return;
    }
    
    for(int i = start + 1; i < N; i++){
        if(visited & (1 << i)) continue;
        combi(i, cnt + 1, visited | (1 << i));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
    }
    
    combi(-1, 0, 0);
    cout << ret;
    return 0;
}