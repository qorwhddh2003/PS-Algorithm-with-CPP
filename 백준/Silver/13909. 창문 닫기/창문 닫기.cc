#include <bits/stdc++.h>
using namespace std;

int n, ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= sqrt(n); i++){
        ret++;
    }
    
    cout << ret;
    return 0;
}