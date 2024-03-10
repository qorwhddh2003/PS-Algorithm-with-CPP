#include <bits/stdc++.h>
using namespace std;

int n, m, temp, ret;
map<int, bool> A, B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> temp;
        A[temp] = true;
    }
    for(int i = 0; i < m; i++){
        cin >> temp;
        B[temp] = true;
    }
    
    for(auto it : A){
        if(A[it.first] && !B[it.first]) ret++;
    }
    
    for(auto it : B){
        if(!A[it.first] && B[it.first]) ret++;
    }
    
    cout << ret;
    return 0;
}
