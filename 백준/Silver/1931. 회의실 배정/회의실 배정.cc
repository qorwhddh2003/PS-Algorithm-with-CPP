#include <bits/stdc++.h>
using namespace std;

int n, to, from, ret = 1;
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from});
    }
    sort(v.begin(), v.end());
    
    tie(to, from) = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i].second < to) continue;
        tie(to, from) = v[i];
        ret++;
    }
    cout << ret;
    return 0;
}
