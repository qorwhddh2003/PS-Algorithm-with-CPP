#include <bits/stdc++.h>
using namespace std;

int n, a, b, g, ret;
vector<int> dis;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a;
    for(int i = 1; i < n; i++){
        cin >> b;
        dis.push_back(b - a);
        a = b;
    }
    
    int g = dis[0];
    for(int i = 1; i < dis.size(); i++){
        g = gcd(g, dis[i]);
    }
    
    for(int i = 0; i < dis.size(); i++){
        ret += (dis[i] / g) - 1;
    }
    cout << ret;
    return 0;
}
