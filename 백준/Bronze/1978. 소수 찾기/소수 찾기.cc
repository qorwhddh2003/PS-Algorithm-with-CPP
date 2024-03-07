#include <bits/stdc++.h>
using namespace std;

int n, temp, ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp == 1) continue;
        
        int prime_cnt = 0;
        for(int i = 2; i < temp; i++){
            if(temp % i == 0) prime_cnt++;
        }
        if(!prime_cnt) ret++;
    }
    cout << ret;
    return 0;
}