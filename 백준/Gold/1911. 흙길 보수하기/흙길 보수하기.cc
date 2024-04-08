#include <bits/stdc++.h>
using namespace std;

int N, L, a, b, d, ret;
vector<pair<int, int>> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    
    int cur = 0;
    for(int i = 0; i < N; i++){
        if(v[i].second <= cur) continue;
        if(cur < v[i].first){
            d = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L ? 1 : 0);
            cur = v[i].first + L * d;
        }else{
            d = (v[i].second - cur) / L + ((v[i].second - cur) % L ? 1 : 0);
            cur = cur + L * d;
        }
        ret += d;
    }
    cout << ret;
    return 0;
}
