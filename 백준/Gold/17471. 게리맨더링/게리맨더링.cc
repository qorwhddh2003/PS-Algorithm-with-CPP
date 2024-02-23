#include <bits/stdc++.h>
using namespace std;

const int MAX = 14, INF = 9e8;
int n, m, a, temp, ret = INF;
int population[MAX], visited[MAX], group[MAX];
vector<int> v[MAX];

pair<int, int> dfs(int here, int group_num){
    visited[here] = 1;
    pair<int, int> ret = {1, population[here]};
    for(int there : v[here]){
        if(visited[there]) continue;
        if(group[there] != group_num) continue;
        pair<int, int> _temp = dfs(there, group_num);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> population[i];
    }
    
    for(int i = 1; i <= n; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> temp;
            v[i].push_back(temp);
            v[temp].push_back(i);
        }
    }
    
    for(int i = 1; i <= (1 << (n - 1)); i++){
        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        int startA = 0, startB = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                group[j + 1] = 1;
                startA = j + 1;
            }else startB = j + 1;
        }
        pair<int, int> blue = dfs(startA, 1);
        pair<int, int> red = dfs(startB, 0);
        if(blue.first + red.first == n){
            ret = min(ret, abs(blue.second - red.second));
        }
    }
    
    cout << (ret == INF ? -1 : ret);
    return 0;
}