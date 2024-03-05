#include <bits/stdc++.h>
using namespace std;

string s;
int b, ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> b;
    
    for(int i = 0; i < s.size(); i++){
        char c = s[s.size() - i - 1];
        if(c >= '0' && c <= '9'){
            ret += pow(b, i) * (c - '0');
        }else{
            ret += pow(b, i) * ((c - 'A') + 10);
        }
    }
    cout << ret;
    return 0;
}
