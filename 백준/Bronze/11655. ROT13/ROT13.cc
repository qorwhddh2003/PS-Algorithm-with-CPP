#include <bits/stdc++.h>
using namespace std;

int asc;
string str;
int main(){
    getline(cin, str);
    
    for(char c : str){
        if(c >= 65 && c <= 90){
            if(c + 13 > 90) c += 13 - 26;
            else c += 13;
        }else if(c >= 97 && c <= 122){
            if(c + 13 > 122) c += 13 - 26;
            else c += 13;
        }
        cout << c;
    }
    
    return 0;
}