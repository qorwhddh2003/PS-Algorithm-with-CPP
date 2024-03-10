#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
map<int, int> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        mp[temp]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        cout << mp[temp] << " ";
    }
    return 0;
}
