#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int visited[2][MAX + 1], a, b, flag, turn = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    if(a == b) {cout << 0; return 0;}
    queue<int> q;
    q.push(a);
    visited[0][b] = 1;
    while(q.size()){
        b += turn;
        if(b > MAX) break;
        if(visited[turn % 2][b]){
            flag = true;
            break;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int now = q.front();
            q.pop();
            for(int next : {now + 1, now - 1, now * 2}){
                if(next < 0 || next > MAX || visited[turn % 2][next]) continue;
                visited[turn % 2][next] = visited[(turn + 1) % 2][next] + 1;
                if(next == b){
                    flag = 1;
                    break;
                }
                q.push(next);
            }
        }
        if(flag) break;
        turn++;
    }
    if(flag) cout << turn;
    else cout << -1;
}