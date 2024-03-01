#include <bits/stdc++.h>
using namespace std;

string a, b;
int arrA[10004], arrB[10004], ret[10004];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    int idx = 0;
    for(int i = a.size() - 1; i >= 0; i--) arrA[idx++] = a[i] - '0';
    idx = 0;
    for(int i = b.size() - 1; i >= 0; i--) arrB[idx++] = b[i] - '0';
    
    int mx = max(a.size(), b.size());
    for(int i = 0; i < mx; i++){
        int sum = arrA[i] + arrB[i] + ret[i];
        ret[i] = sum % 10;
        ret[i + 1] = sum / 10;
    }
    if(ret[mx] > 0) cout << ret[mx];
    for(int i = mx - 1; i >= 0; i--) cout << ret[i];
    
    return 0;
}