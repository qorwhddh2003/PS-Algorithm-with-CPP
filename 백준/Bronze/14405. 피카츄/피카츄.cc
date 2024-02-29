#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int idx = 0;
    bool flag = 0;
    while(idx < s.size()){
        if(s.substr(idx, 2) == "pi" || s.substr(idx, 2) == "ka"){
            idx += 2;
        }else if(s.substr(idx, 3) == "chu"){
            idx += 3;
        }else{
            flag = 1;
            break;
        }
    }
    cout << (!flag ? "YES" : "NO");
    return 0;
}