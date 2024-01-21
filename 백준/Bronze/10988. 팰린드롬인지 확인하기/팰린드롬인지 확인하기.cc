#include <bits/stdc++.h>
using namespace std;

string str, rev_str;
int main(){
    cin >> str;
    rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    
    if(str == rev_str){
        cout << 1;
    }else{
        cout << 0;
    }
    
    return 0;
}