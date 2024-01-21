#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string str;
bool flag = 0;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        cnt[(char)str[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(cnt[i] >= 5){
            flag = 1;
            cout << (char)(i + 'a');
        }
    }
    
    if(flag == 0) cout << "PREDAJA";
    
    return 0;
}