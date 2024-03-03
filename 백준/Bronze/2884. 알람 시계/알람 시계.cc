#include <bits/stdc++.h>
using namespace std;

int h, m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> m;
    
    int t = h * 60 + m - 45;
    if(t < 0) t += 60 * 24;
    cout << (t / 60) << " " << (t % 60);
    return 0;
}
