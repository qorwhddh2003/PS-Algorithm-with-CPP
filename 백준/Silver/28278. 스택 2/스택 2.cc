#include <bits/stdc++.h>
using namespace std;

int t, type, x, idx = -1;
int arr[1000001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> type;
        if(type == 1){
            cin >> x;
            arr[++idx] = x;
        }else if(type == 2){
            cout << (idx == -1 ? -1 : arr[idx--]) << "\n";
        }else if(type == 3){
            cout << idx + 1 << "\n";
        }else if(type == 4){
            cout << (idx == -1 ? 1 : 0) << "\n";
        }else{
            cout << (idx == -1 ? -1 : arr[idx]) << "\n";
        }
    }
    
    return 0;
}