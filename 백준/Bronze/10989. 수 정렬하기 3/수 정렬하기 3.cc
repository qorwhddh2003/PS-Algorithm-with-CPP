#include <bits/stdc++.h>
using namespace std;

int n, temp;
int a[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a[temp]++;
    }
    
    for(int i = 1; i < 10001; i++){
        if(a[i]){
            for(int j = 0; j < a[i]; j++){
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}
