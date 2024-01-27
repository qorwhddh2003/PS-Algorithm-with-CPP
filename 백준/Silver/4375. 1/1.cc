#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
    while(cin >> n){
        ll num = 1, ret = 1;
        while(true){
            if(num % n == 0){
                cout << ret << '\n';
                break;
            }else{
                num = (num * 10) + 1;
                num %= n;
                ret++;
            }
        }
    }
    return 0;
}