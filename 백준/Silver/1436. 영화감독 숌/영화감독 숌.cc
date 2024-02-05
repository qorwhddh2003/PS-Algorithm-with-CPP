#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool isCheck666(string s){
    for(int i = 0; i <  s.size(); i++){
        if(s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6'){
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i = 666; i <= 100000000; i++){
        if(isCheck666(to_string(i))){
            cnt++;
            if(n == cnt){
                cnt = i;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}