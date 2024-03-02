#include <bits/stdc++.h>
using namespace std;

int n, cost = 9e8;
struct info{
    int mp, mf, ms, mv, cost;
} a[16], target;

vector<int> ret;
map<int, vector<vector<int>>> mp;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> target.mp >> target.mf >> target.ms >> target.mv;
    for(int i = 0; i < n; i++){
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }
    
    for(int i = 1; i < (1 << n); i++){
        info temp = {0,};
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                temp.mp += a[j].mp;
                temp.mf += a[j].mf;
                temp.ms += a[j].ms;
                temp.mv += a[j].mv;
                temp.cost += a[j].cost;
                v.push_back(j + 1);
            }
        }
        
        if(target.mp <= temp.mp && target.mf <= temp.mf && target.ms <= temp.ms && target.mv <= temp.mv){
            if(cost >= temp.cost){
                cost = temp.cost;
                mp[cost].push_back(v);
            }
        }
    }
    
    sort(mp[cost].begin(), mp[cost].end());
    
    if(cost == 9e8) cout << -1;
    else{
        cout << cost << "\n";
        for(int i : mp[cost][0]) cout << i << " ";
    }
    return 0;
}
