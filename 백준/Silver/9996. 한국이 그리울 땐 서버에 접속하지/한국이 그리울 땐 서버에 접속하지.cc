#include <bits/stdc++.h>
using namespace std;

int n, idx;
string s, prefix, suffix;
int main(){
    cin >> n;
    cin >> s;
    idx = s.find("*");
    prefix = s.substr(0, idx);
    suffix = s.substr(idx + 1);
    
    while(n--){
        cin >> s;
        if(prefix.size() + suffix.size() > s.size()){
            cout << "NE\n";
        }else{
            if(s.substr(0, prefix.size()) == prefix && s.substr(s.size() - suffix.size()) == suffix){
                cout << "DA\n";
            }else{
                cout << "NE\n";
            }
        }
    }
    
    return 0;
}