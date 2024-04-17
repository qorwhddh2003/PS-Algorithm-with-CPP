#include <bits/stdc++.h>
using namespace std;

int X, ret;
int main(){
    cin >> X;
    while(X > 0){
        if(X & 1) ret++;
        X /= 2;
    }
    cout << ret;
    return 0;
}