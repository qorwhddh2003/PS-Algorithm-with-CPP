#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k;
int visited[MAX + 1], tracking[MAX + 1];
vector<int> ret;

int main(){
    cin >> n >> k;
    
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    tracking[n] = -1;
    
    while(q.size()){
        int now = q.front();
        q.pop();
        if(now == k) break;
        for(int next : {now + 1, now - 1, now * 2}){
            if(0 > next || next > MAX || visited[next]) continue;
            q.push(next);
            visited[next] = visited[now] + 1;
            tracking[next] = now;
        }
    }
    
    for(int i = k; i != -1; i = tracking[i]){
        ret.push_back(i);
    }
    reverse(ret.begin(), ret.end());
    cout << visited[k] - 1 << "\n";
    for(int i : ret) cout << i << " ";
    return 0;
}