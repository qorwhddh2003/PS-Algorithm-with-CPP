#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret, temp;
int main(){
    cin >> n >> m >> j;    
    int l = 1, r, temp;
    for(int i = 0; i < j; i++){
        r = l + m - 1;
        cin >> temp;
        if(temp >= l && temp <= r) continue;
        if(l > temp){
            ret += l - temp;
            l = temp;
        }else if(l < temp){
            ret += temp - r;
            l += temp - r;
        }
    }
    
    cout << ret;
    return 0;    
}
