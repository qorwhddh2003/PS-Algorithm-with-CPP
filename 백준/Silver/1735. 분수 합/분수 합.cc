#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b >> c >> d;
    int child = (a * d) + (b * c);
    int parent = (b * d);
    int g = gcd(child, parent);
    cout << (child / g) << " " << (parent / g);
    return 0;
}