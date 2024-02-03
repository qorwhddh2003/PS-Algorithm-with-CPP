#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> mp, mp2;
vector<int> v;

bool cmp(int a, int b){
    if(mp[a] == mp[b]){
        return mp2[a] < mp2[b];
    }
    
    return mp[a] > mp[b];
}

int main(){
    cin >> n >> c;
    int val;
    for(int i = 0; i < n; i++){
        cin >> val;
        mp[val]++;
        if(mp2[val] == 0) mp2[val] = i + 1;
    }
    
    for(auto it : mp){
        for(int i = 0; i < it.second; i++){
            v.push_back(it.first);
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    for(int i : v) cout << i << " ";
    return 0;
}