#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    
    int arrive = 0;
    for(int i = 0; i < n; i++){
        if(arrive < v[i].first){
            arrive = v[i].first + v[i].second;
        }else if(arrive >= v[i].first){
            arrive += v[i].second;
        }
    }
    cout << arrive;
    return 0;
}