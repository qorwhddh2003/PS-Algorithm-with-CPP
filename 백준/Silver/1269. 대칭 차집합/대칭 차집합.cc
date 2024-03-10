#include <bits/stdc++.h>
using namespace std;

int n, m, temp, ret;
map<int, bool> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        cin >> temp;
        if(mp[temp]){
            mp.erase(temp);
        }else{
            mp[temp] = true;
        }
    }
    
    cout << mp.size();
    return 0;
}
