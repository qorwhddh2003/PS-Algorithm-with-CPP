#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<pair<int, int>> v;
map<int, int> mp;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back({temp, i});
    }
    sort(v.begin(), v.end());
    
    int rank = 1;
    for(int i = 0; i < n; i++){
        if(mp[v[i].first] == 0){
            mp[v[i].first] = rank++;
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    for(auto it : v){
        cout << mp[it.first]-1 << " ";
    }
    return 0;
}
