#include <bits/stdc++.h>
using namespace std;

int N, M, temp, ret = 1e6, r1, r2, c1, c2;
vector<pair<int, int>> chicken_list, house_list, b;

void combi(int start, vector<pair<int, int>> b){
    if(b.size() == M){
        int res = 0;
        for(int i = 0; i < house_list.size(); i++){
            int mn = 1e6;
            tie(r1, c1) = house_list[i];
            for(int j = 0; j < b.size(); j++){
                tie(r2, c2) = b[j];
                mn = min(mn, abs(r1 - r2) + abs(c1 - c2));
            }
            res += mn;
        }
        ret = min(ret, res);
        return; 
    }
    
    for(int i = start + 1; i < chicken_list.size(); i++){
        b.push_back(chicken_list[i]);
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
            if(temp == 1) house_list.push_back({i+1, j+1});
            else if(temp == 2) chicken_list.push_back({i+1, j+1});
        }
    }
    combi(-1, b);
    cout << ret;
    return 0;
}