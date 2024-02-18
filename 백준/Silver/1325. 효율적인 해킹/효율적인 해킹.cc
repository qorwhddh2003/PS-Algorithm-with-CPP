#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, mx;
int visited[10001], dp[10001];
vector<int> adj[10001];

int go(int here){
    int ret = 1;
    visited[here]  = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        ret += go(there);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        fill(&visited[0], &visited[0] + 10001, 0);
        dp[i] = go(i);
        mx = max(mx, dp[i]);
    }
    
    for(int i = 1; i <= n; i++){
        if(mx == dp[i]) cout << i << " ";
    }
}