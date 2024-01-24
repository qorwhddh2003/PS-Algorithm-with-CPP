#include <bits/stdc++.h>
using namespace std;

int cnt[26], flag;
string name, ret;
char mid;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> name;
    for(char c : name) cnt[c - 'A']++;
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i - 'A'] & 1) {
            mid = char(i);
            cnt[i - 'A']--;
            flag++;
            
        }
        if(flag == 2) break;
        for(int j = 0; j < cnt[i - 'A']; j += 2){
            ret = char(i) + ret;
            ret += char(i);
        }
    }
    if(flag == 2) cout << "I'm Sorry Hansoo";
    else{
        if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
        cout << ret;
    }
    
    return 0;
}