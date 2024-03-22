#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, a, b, ret;
vector<pair<ll, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;
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
    
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    
    while(pq.size()){
        ret += pq.top(); pq.pop();
    }
    cout << ret;
    return 0;
}