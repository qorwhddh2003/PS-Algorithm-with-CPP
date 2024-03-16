#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b %  a, a);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int A, B;
int main(){
    cin >> A >> B;
    cout << gcd(A, B) << "\n";
    cout << lcm(A, B);
    return 0;
}