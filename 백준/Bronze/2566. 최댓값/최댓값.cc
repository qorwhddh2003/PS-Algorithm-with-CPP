#include <bits/stdc++.h>
using namespace std;

int temp;
int y = 1, x = 1, mx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> temp;
            if(temp > mx){
                mx = temp, y = i + 1, x = j + 1;
            }
        }
    }
    cout << mx << "\n" << y << " " << x;
    return 0;
}
