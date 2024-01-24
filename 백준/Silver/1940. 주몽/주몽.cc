#include <bits/stdc++.h>
using namespace std;

int n, m, a, ret;
vector<pair<int, int>> v;


int main(){
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back({a, 0});
    }
    for(int i = 0; i < n - 1; i++){
        if(v[i].second == 1) continue;
        if(m - v[i].first < 0) continue;
        if(m - v[i].first == v[i].first) continue;
        
        for(int j = i + 1; j < n; j++){
            if(v[j].second == 1) continue;
            if(m - v[i].first - v[j].first == 0){
                ret++;
                v[i].first = 1;
                v[j].first = 1;
                break;
            }
        }
    }
    
    cout << ret;
}