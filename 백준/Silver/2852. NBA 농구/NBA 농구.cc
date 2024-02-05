#include <bits/stdc++.h>
using namespace std;

int N, team, ret1, ret2, score;
string s;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    v.push_back({0, 0});
    for(int i = 0; i < N; i++){
        cin >> team >> s;
        v.push_back({team, stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3))});
    }
    v.push_back({0, 48 * 60});
    
    int prev = -1;
    for(int i = 1; i < v.size(); i++){
        auto it = v[i];
        
        if(score > 0){
            ret1 += (it.second - v[i - 1].second);
        }else if(score < 0){
            ret2 += (it.second - v[i - 1].second);
        }
        
        if(it.first == 1) score++;
        else if(it.first == 2) score--;
    }
    printf("%02d:%02d\n", ret1 / 60, ret1 %  60);
    printf("%02d:%02d\n", ret2 / 60, ret2 %  60);
    return 0;
}