#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret;
int apple_loc;

int main(){
    cin >> n >> m >> j;
    int cur = 1;
    while(j--){
        cin >> apple_loc;
        
        if(cur <= apple_loc && (cur + (m-1)) >= apple_loc) continue;
        while(true){
            if(cur < apple_loc) cur++;
            else cur--;
            ret++;
            
            if(cur <= apple_loc && cur + (m-1) >= apple_loc) break;
        }
    }
    
    cout << ret;
    return 0;
}