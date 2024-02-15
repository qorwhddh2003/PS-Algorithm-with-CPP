#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000;
int n, k, temp;
int visited[MAX+1], tracking[MAX + 1];
vector<int> ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    
    visited[n] = 1;
    tracking[n] = -1;
    queue<int> q;
    q.push(n);
    
    while(q.size()){
        int now = q.front();
        q.pop();
        if(now == k) break;
        for(int next : {now * 2, now - 1, now + 1}){
            if(0 <= next && next <= MAX){
                if(visited[next]) continue;
                q.push(next);
                visited[next] = visited[now] + 1;
                tracking[next] = now;
            }
        }
    }
    
    for(int i = k; i != -1; i = tracking[i]){
        ret.push_back(i);
    }
    cout << visited[k] - 1 << "\n";
    reverse(ret.begin(), ret.end());
    for(int i : ret) cout << i << " ";
    return 0;
}