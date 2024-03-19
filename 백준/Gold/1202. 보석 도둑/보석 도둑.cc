#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K, M, V, C, ret;
vector<pair<ll, ll>> vec;
vector<ll> bag;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> M >> V;
        vec.push_back({M, V});
    }
    for(int i = 0; i < K; i++){
        cin >> C;
        bag.push_back(C);
    }
    sort(vec.begin(), vec.end());
    sort(bag.begin(), bag.end());
    
    priority_queue<int> pq;
    int j = 0;
    for(int i = 0; i < K; i++){
        while(j < N && vec[j].first <= bag[i]) pq.push(vec[j++].second);
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
    }
    
    cout << ret;
    return 0;
}
