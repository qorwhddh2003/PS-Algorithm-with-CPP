#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, ret = 9e8;
int a[MAX + 4];
string s;

void go(int here){
    if(here == n){
        int sum = 0;
        for(int i = 1; i <= (1 << (n - 1)); i *= 2){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(a[j] & i) cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    
    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        int value = 1;
        for(int j = 0; j < n; j++){
            if(s[j] == 'T') a[i] |= value;
            value *= 2;
        }
    }
    go(0);
    cout << ret << "\n";
}