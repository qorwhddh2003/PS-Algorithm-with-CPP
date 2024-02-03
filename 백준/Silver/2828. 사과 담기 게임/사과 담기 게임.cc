#include <bits/stdc++.h>
using namespace std;

int n, m, j;
int main(){
    cin >> n >> m >> j;
    
    int l = 1, r, temp, sum=0;
    for(int i = 0; i < j; i++){
        cin >> temp;
        r = l + m - 1;
        if(l <= temp && temp <= r) continue;
        if(temp < l){
            sum += l - temp;
            l = temp;
        }else if(l < temp){
            sum += temp - r;
            l += temp - r;
        }
    }
    
    cout << sum;
    return 0;
}