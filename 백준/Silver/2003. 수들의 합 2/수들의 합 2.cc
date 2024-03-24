#include <bits/stdc++.h>
using namespace std;

int n, m, temp, s, e, ret;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    
    int sum = 0;
    while(s < n){
        if(m <= sum || e == n) sum -= v[s++];
        else sum += v[e++];
        if(sum == m) ret++;
    }
    cout << ret;
    return 0;
}
