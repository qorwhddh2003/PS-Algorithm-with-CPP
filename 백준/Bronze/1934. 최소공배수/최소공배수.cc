#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }
    
    return 0;
}