#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<string, int> mp;
        for(int i = 0; i < n; i++){
            cin >> s >> s;
            mp[s]++;
        }
        
        long long ret = 1;
        for(auto m : mp){
            ret *= ((long long) m.second + 1);
        }
        
        ret--;
        cout << ret << '\n';
    }
}