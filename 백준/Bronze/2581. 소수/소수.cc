#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    
    for(int k = n; k <= m; k++){
        if(k == 1) continue;
        int i = 0;
        for(i = 2; i <= k; i++){
            if(k % i == 0) break;
        }
        if(i == k) ret.push_back(i);
    }
    
    if(ret.size()){
        int sum = 0;
        for(int i : ret){
            sum += i;
        }
        cout << sum << "\n" << ret[0];
    }else{
        cout << -1;
    }
    
    return 0;
}