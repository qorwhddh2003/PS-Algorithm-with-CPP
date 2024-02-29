#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
vector<int> adj[1001];
int visited[1001];

void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        dfs(there);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        fill(visited, visited + 1001, 0);
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            dfs(i);
            cnt++;
        }
        
        if(m == n - 1 && cnt == 1) cout << "tree\n";
        else cout << "graph\n";
        
    }
    
    return 0;
}