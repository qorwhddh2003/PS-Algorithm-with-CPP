#include <bits/stdc++.h>
using namespace std;

int asc;
string str, ret;
int main(){
    getline(cin, str);
    
    for(char ch : str){
        if(ch == ' ' || isdigit(ch)){
            ret += ch;
        }
        else{
            asc = ch + 13;
            if(asc > 122 || (asc > 90 && asc < 97) || (asc > 90 && ch <= 90)) asc -= 26;
            ret += asc;
        }
    }
    cout << ret;
    
    return 0;
}