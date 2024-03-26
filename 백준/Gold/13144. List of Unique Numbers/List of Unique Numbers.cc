#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, e, ret;
ll visited[100001];
int a[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    while(e < n){
        if(visited[a[e]]){
            ret += (e - s);
            visited[a[s]] = 0;
            s++;
        }else{
            visited[a[e]] = 1;
            e++;
        }
    }
    
    ret += (e - s + 1) * (e - s) / 2;
    cout << ret;
    return 0;
}
