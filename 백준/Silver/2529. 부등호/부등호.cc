#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll K, mx_ret, mn_ret = 9e10;
vector<char> oper_str;
char temp;

string print(ll num){
    string temp = "00" + to_string(num);
    return temp.substr(temp.size() - K - 1);
}

bool oper(char a, ll b, ll c){
    if(a == '<') return b < c;
    else return b > c;
}

void go(ll here, ll ret, ll visited){
    if(here == K){
        mx_ret = max(mx_ret, ret);
        mn_ret = min(mn_ret, ret);
        return;
    }
    
    for(ll i = 0; i <= 9; i++){
        if(visited & (1 << i)) continue;
        if(here == -1 || oper(oper_str[here], to_string(ret).back() - '0', i)){
            go(here + 1, ret * 10 + i, visited | (1 << i));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K;
    for(ll i = 0; i < K; i++){
        cin >> temp;
        oper_str.push_back(temp);
    }
    
    go(-1, {}, 0);
    cout << print(mx_ret) << "\n" << print(mn_ret);
    return 0;
}