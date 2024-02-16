#include <bits/stdc++.h>
using namespace std;

int n, ret = -1e18;
string s;
vector<int> num;
vector<char> oper_vec;

int oper(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}

void go(int here, int _num){
    if(here == num.size() - 1){
        ret = max(ret, _num);
        return;
    }
    go(here + 1, oper(oper_vec[here], _num, num[here + 1]));
    if(here + 2 <= num.size() - 1){
        int temp = oper(oper_vec[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_vec[here], _num, temp));
    }
}

int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_vec.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret;
    return 0;
}
