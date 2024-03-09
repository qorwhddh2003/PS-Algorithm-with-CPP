#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(a[i] + a[j] + a[k] <= m){
                    ret = max(ret, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    
    cout << ret;
    return 0;
}