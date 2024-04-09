#include <bits/stdc++.h>
using namespace std;

int N, mx = -1e9, mn = 1e9;
int arr[11], oper[4];

int cal(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
    if(a == '/'){
        if(b > 0) return b / c;
        else return -(abs(b) / c);
    }
}

void go(int idx, int sum, int a, int b, int c, int d){
    if(idx == N){
        mx = max(mx, sum);
        mn = min(mn, sum);
        return;
    }
    if(a) go(idx + 1, cal('+', sum, arr[idx]), a - 1, b, c, d);
    if(b) go(idx + 1, cal('-', sum, arr[idx]), a, b - 1, c, d);
    if(c) go(idx + 1, cal('*', sum, arr[idx]), a, b, c - 1, d);
    if(d) go(idx + 1, cal('/', sum, arr[idx]), a, b, c, d - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++) cin >> oper[i];
    go(1, arr[0], oper[0], oper[1], oper[2], oper[3]);
    cout << mx << "\n" << mn;
    return 0;
}



