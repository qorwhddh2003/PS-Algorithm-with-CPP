#include <bits/stdc++.h>
using namespace std;

int N, M, temp, ret = 1e6;
vector<pair<int, int>> house, chicken;

int getDistance(vector<int> b){
    int res = 0;
    for(pair<int, int> i : house){
        int mn = 1e6;
        for(int j : b){
            mn = min(mn, abs(i.first - chicken[j].first) + abs(i.second - chicken[j].second));
        }
        res += mn;
    }
    return res;
}

void combi(int start, vector<int> b){
    if(b.size() == M){
        ret = min(ret, getDistance(b));
        return;
    }
    
    for(int i = start + 1; i < chicken.size(); i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;
            if(temp == 1) house.push_back({i + 1, j + 1});
            else if(temp == 2) chicken.push_back({i + 1, j + 1});
        }
    }
    
    vector<int> b;
    combi(-1, b);
    cout << ret;
    return 0;
}