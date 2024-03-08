#include <bits/stdc++.h>
using namespace std;

int a, b, v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> v;
    if((v - a) % (a - b) == 0){
        cout << (v - a) / (a - b) + 1;
    }else{
        cout << (v - a) / (a - b) + 2;
    }
    return 0;
}
