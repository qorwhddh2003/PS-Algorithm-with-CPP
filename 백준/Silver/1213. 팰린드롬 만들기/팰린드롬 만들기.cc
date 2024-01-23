#include <bits/stdc++.h>
using namespace std;

int odd_num;
string s, ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    
    map<char, int> mp;
    for(char ch : s){
        mp[ch]++;
    }
    
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        char key = (*it).first;
        int value = (*it).second;
        
        if(value % 2 != 0) {
            ret = ret.substr(0, ret.size() / 2) + key + ret.substr(ret.size() / 2);
            odd_num++;
            value--;
        }
        
        for(int i = 0; i < value; i++){
            if(i % 2 == 0) ret = key + ret;
            else ret += key;
        }
    }
    
    if(odd_num > 1) cout << "I'm Sorry Hansoo";
    else cout << ret << '\n';
}