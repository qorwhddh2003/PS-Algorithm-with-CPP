#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
int cnt[501];
vector<pair<int, int>> v;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(v[i].second > v[j].second && mx < cnt[j]){
                mx = cnt[j];
            }
        }
        cnt[i] = mx + 1;
        ret = max(ret, cnt[i]);
    }
    
    cout << N - ret;
    return 0;
}
