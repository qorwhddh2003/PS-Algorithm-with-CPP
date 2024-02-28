#include <bits/stdc++.h>
using namespace std;

int n, temp, ret;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        // cout << i << " : " << s << " ";
        if(s == "add"){
            cin >> temp;
            ret |= (1 << (temp - 1));
        }else if(s == "remove"){
            cin >> temp;
            ret &= ~(1 << (temp - 1));
        }else if(s == "check"){
            cin >> temp;
            if(ret & (1 << (temp - 1))) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if(s == "toggle"){
            cin >> temp;
            ret ^= (1 << (temp - 1));
        }else if(s == "all"){
            ret = (1 << 20) - 1;
        }else if(s == "empty"){
            ret = 0;
        }
    }
    
    return 0;
}