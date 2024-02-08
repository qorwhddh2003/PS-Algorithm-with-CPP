#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, ret;
int visited[10001];
vector<int> adj[10001], v;

int dfs(int here){
    int ret = 1;
    visited[here] = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        adj[B].push_back(A);
    }
    
    for(int i = 1; i <= N; i++){
        fill(&visited[0], &visited[10001], 0);
        int cnt = dfs(i);
        if(cnt > ret){
            v.clear();
            v.push_back(i);
            ret = cnt;
        }else if(cnt == ret){
            v.push_back(i);
        }
    }
    for(int i : v) cout << i << " ";
}