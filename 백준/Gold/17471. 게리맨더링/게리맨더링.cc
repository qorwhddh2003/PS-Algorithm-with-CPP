#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int N, M, temp, red, blue, ret = 9e8;
int population[MAX], team[MAX], visited[MAX];
vector<int> adj[MAX];

pair<int, int> dfs(int here, int color){
    visited[here] = 1;
    pair<int, int> ret = {1, population[here]};
    for(int there : adj[here]){
        if(visited[there] || color != team[there]) continue;
        pair<int, int> temp = dfs(there, color);
        ret.first += temp.first;
        ret.second += temp.second;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> population[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> M;
        for(int j = 0; j < M; j++){
            cin >> temp;
            adj[i].push_back(temp - 1);
            adj[temp - 1].push_back(i);
        }
    }
    
    for(int i = 1; i <= (1 << (N - 1)); i++){
        fill(visited, visited + MAX, 0);
        fill(team, team + MAX, 0);
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                team[j] = 1;
                red = j;
            }else{
                blue = j;
            }
        }
        pair<int, int> red_team = dfs(red, 1);
        pair<int, int> blue_team = dfs(blue, 0);
        if(red_team.first + blue_team.first == N){
            ret = min(ret, abs(red_team.second - blue_team.second));
        }
    }
    cout << (ret == 9e8 ? -1 : ret);
    return 0;
}