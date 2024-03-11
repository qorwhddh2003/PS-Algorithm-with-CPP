#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, temp, prev, dis, ret;
vector<int> v;

int gcd(int num1, int num2){
    if(num1 == 0) return num2;
    return gcd(num2 % num1, num1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(i > 0){
            v.push_back(temp - prev);
        }
        prev = temp;
    }
    
    dis = gcd(v[0], v[1]);
    for(int i = 2; i < v.size(); i++){
        dis = gcd(dis, v[i]);
    }
    
    for(int i : v){
        ret += (i / dis) - 1;
    }
    
    cout << ret;
    return 0;
}