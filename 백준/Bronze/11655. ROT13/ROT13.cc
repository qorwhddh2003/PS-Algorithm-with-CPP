#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    getline(cin, s);
    
    for(char c : s){
        if(c >= 'A' && c <= 'Z'){
            if(c + 13 > 90) c += 13 - 26;
            else c += 13;
        }else if(c >= 'a' && c <= 'z'){
            if(c + 13 > 122) c += 13 - 26;
            else c += 13;
        }
        cout << c;
    }
    
    return 0;
}