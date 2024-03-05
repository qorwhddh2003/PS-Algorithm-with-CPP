#include <bits/stdc++.h>
using namespace std;

int n, b;
string ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    while(n != 0){
        char tmp;
        if(n % b >= 10){
            tmp = (n % b - 10) + 'A';
        }else{
            tmp = (n % b) + '0';
        }
        ret = tmp + ret;
        n /= b;
    }
    cout << ret;
    return 0;
}
