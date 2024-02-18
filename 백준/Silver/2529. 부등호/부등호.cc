#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, mx = 0, mn = 1e18;
int visited[10];
char c;
vector<ll> num;
vector<char> oper_str;

void print(ll _mx, ll _mn){
    string mx_str = "0" + to_string(mx);
    string mn_str = "0" + to_string(mn);
    mx_str = mx_str.substr(mx_str.size() - (n + 1));
    mn_str = mn_str.substr(mn_str.size() - (n + 1));
    cout << mx_str << "\n" << mn_str;
}

bool oper(char a, ll b, ll c){
    if(a == '<'){
        if(b < c) return true;
        else return false;
    }else if(a == '>'){
        if(b > c) return true;
        else return false;
    }
}

void go(ll here, ll _num, ll ret){
    ret += (_num * pow(10, n - here));
    if(here == n){
        mx = max(mx, ret);
        mn = min(mn, ret);
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(visited[i]) continue;
        if(oper(oper_str[here], _num, num[i])){
            visited[i] = 1;
            go(here + 1, num[i], ret);
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        oper_str.push_back(c);
    }
    for(int i = 0; i <= 9; i++) num.push_back(i);
    for(int i = 0; i <= 9; i++){
        visited[i] = 1;
        go(0, i, 0);
        visited[i] = 0;
    }
    print(mx, mn);
    return 0;
}