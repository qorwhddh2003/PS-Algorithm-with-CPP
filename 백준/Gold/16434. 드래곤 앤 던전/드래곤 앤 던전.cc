#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Soldier{
    ll maxHP, curHP, atk;
} soldier;

struct RoomInfo{
    ll t, a, h;
};

ll N, t, a, h, atk_temp, lo = 1, hi = 1e18, ret = 1e18;
vector<RoomInfo> v;

bool check(ll mid){
    soldier = {mid, mid, atk_temp};
    for(int i = 0; i < N; i++){
        if(v[i].t == 1){ 
            ll cnt = v[i].h / soldier.atk;
            if(v[i].h % soldier.atk) cnt++;
            if(soldier.curHP - (v[i].a * (cnt - 1)) <= 0) return false;
            soldier.curHP -= (v[i].a * (cnt - 1));
        }else{
            soldier.atk += v[i].a;
            soldier.curHP = min(soldier.maxHP, soldier.curHP + v[i].h);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> atk_temp;
    for(int i = 0; i < N; i++){
        RoomInfo temp;
        cin >> temp.t >> temp.a >> temp.h;
        v.push_back(temp);
    }
    
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            ret = min(mid, ret);
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << ret;
    return 0;
}