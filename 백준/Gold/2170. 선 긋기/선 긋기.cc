#include <bits/stdc++.h>
using namespace std;
#define y aaaa

int N, x, y, s, e, ret = -9e8;
vector<pair<int, int>> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    
    int sum = 0;
    tie(s, e) = v[0];
    for(int i = 1; i < N; i++){
        if(e >= v[i].first) e = max(e, v[i].second);
        else{
            sum += (e - s);
            ret = max(ret, sum);
            tie(s, e) = v[i];
        }
    }
    sum += (e - s);
    ret = max(ret, sum);
    cout << ret;
    return 0;
}