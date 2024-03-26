#include <bits/stdc++.h>
using namespace std;

const int INF = 9e8;
int n, k, ret;
int a[101], visisted[101];
set<int> plug;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < k; i++){
        if(visisted[a[i]]) continue;
        if(plug.size() == n){
            int last_idx = 0, value;
            for(auto it = plug.begin(); it != plug.end(); it++){
                int pick = INF;
                for(int j = i + 1; j < k; j++){
                    if(*it == a[j]){
                        pick = j; break;
                    }
                }
                if(last_idx < pick){
                    last_idx = pick;
                    value = *it;
                }
            }
            visisted[value] = 0;
            plug.erase(value);
            ret++;
        }
        visisted[a[i]] = 1;
        plug.insert(a[i]);
    }
    
    cout << ret;
    return 0;
}
