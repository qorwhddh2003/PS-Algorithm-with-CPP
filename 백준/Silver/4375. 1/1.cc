#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    
    while(cin >> n){
        int num = 1, idx = 1;
        
        while(true){
            if(num % n == 0) break;
            num = (num * 10) + 1;
            num %= n;
            idx++;
        }
        cout << idx << "\n";
    }
    
    return 0;
}