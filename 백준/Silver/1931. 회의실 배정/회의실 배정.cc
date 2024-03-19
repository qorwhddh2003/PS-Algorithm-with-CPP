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
    
    int prev = 0;
    for(int i = 0; i < v.size(); i++){
        tie(to, from) = v[i];
        if(i > 0){
            if(v[prev].first <= from){
                ret++;
                prev = i;
            }
        }
    }
    cout << ret;
    return 0;
}
