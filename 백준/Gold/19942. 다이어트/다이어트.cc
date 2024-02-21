#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, temp[4], a, b, c, d, e, ret = INF;
bool flag = 0;
struct Nutrient{
    int mp, mf, ms, mv, cost;
    vector<int> idx;
} info[16];
vector<int> retV;
map<int, vector<vector<int>>> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < 4; i++) cin >> temp[i];
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d >> e;
        info[i] = {a, b, c, d, e};
    }
    
    for(int i = 1; i < (1 << n); i++){
        Nutrient nutrient_temp = {0, 0, 0, 0, 0};
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                nutrient_temp.mp += info[j].mp;
                nutrient_temp.mf += info[j].mf;
                nutrient_temp.ms += info[j].ms;
                nutrient_temp.mv += info[j].mv;
                nutrient_temp.cost += info[j].cost;
                nutrient_temp.idx.push_back(j + 1);
            }
        }
        
        if(nutrient_temp.mp >= temp[0] && nutrient_temp.mf >= temp[1] && nutrient_temp.ms >= temp[2] && nutrient_temp.mv >= temp[3]){
            if(ret >= nutrient_temp.cost){
                ret = nutrient_temp.cost;
                mp[ret].push_back(nutrient_temp.idx);
            }
        }
    }
    
    if(ret == INF) cout << -1;
    else{
        sort(mp[ret].begin(), mp[ret].end());
        cout << ret << "\n";
        for(int i : mp[ret][0]){
            cout << i << " ";
        }
    }
    return 0;
}
