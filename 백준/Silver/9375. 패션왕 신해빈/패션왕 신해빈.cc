#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
string s;
ll ret;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        map<string, int> mp;
        ret = 1;
        
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s >> s;
            mp[s]++;
        }
        
        for(auto i : mp){
            ret *= (ll)(i.second + 1);
        } 
        
        cout << ret - 1 << '\n';
    }
}
