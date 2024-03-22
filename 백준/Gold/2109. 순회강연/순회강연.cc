#include <bits/stdc++.h>
using namespace std;

int n, d, p, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            pq.pop();
        }
    }
    
    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }
    cout << ret;
    return 0;
}