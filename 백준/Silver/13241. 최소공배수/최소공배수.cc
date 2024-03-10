#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, a, b;

ll gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

ll lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
}