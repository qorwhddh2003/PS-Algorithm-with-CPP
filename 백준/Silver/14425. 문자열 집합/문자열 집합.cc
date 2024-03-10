#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
string s;
map<string, bool> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s] = true;
    }
    
    for(int i = 0; i < m; i++){
        cin >> s;
        if(mp[s]) ret++;
    }
    
    cout << ret;
    return 0;
}
