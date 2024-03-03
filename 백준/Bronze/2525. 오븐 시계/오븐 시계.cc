#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    int t = a * 60 + b + c;
    if(t / 60 >= 24) t -= (60 * 24);
    cout << (t / 60) << " " << (t % 60);
    return 0;
}
