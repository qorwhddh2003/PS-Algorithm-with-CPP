#include <bits/stdc++.h>
using namespace std;

const int damage[6][3] = {
  {9, 3, 1},
  {9, 1, 3},
  {3, 1, 9},
  {3, 9, 1},
  {1, 3, 9},
  {1, 9, 3},
};


int n;
int a[61][61][61];
struct A {
    int a, b, c;
} scv;

int main(){
    cin >> n;
    cin >> scv.a >> scv.b >> scv.c;
    
    queue<A> q;
    q.push(scv);
    a[scv.a][scv.b][scv.c] = 1;
    while(q.size()){
        A now = q.front();
        q.pop();
        if(now.a == 0 && now.b == 0 && now.c == 0) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, now.a - damage[i][0]);
            int nb = max(0, now.b - damage[i][1]);
            int nc = max(0, now.c - damage[i][2]);
            if(a[na][nb][nc]) continue;
            a[na][nb][nc] = a[now.a][now.b][now.c] + 1;
            q.push({na, nb, nc});
        }
    }
    
    cout << a[0][0][0]-1;
    return 0;
}