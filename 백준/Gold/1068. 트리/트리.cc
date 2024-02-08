#include <bits/stdc++.h>
using namespace std;

int N, temp, r, root;
vector<int> adj[50];

int dfs(int here){
    int ret = 0, child = 0;
    for(int there : adj[here]){
        if(there == r) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1;
    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        if(temp == -1) root = i;
        else adj[temp].push_back(i);
    }
    cin >> r;
    if(r == root) cout << 0;
    else cout << dfs(root);
    return 0;
}