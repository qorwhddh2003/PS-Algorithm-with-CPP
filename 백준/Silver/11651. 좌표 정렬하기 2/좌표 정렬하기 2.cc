#include <bits/stdc++.h>
using namespace std;

int n;
int y, x;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> y >> x;
        vec.push_back({x, y});
    }
    sort(vec.begin(), vec.end());
    for(pair<int, int> p : vec){
        cout << p.second << " " << p.first << "\n";
    }
    
    return 0;
}