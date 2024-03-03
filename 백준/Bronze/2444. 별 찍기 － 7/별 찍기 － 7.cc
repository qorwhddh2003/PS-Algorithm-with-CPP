#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 1; j < (i + 1) * 2; j++) cout << "*";
        cout << "\n";
    }
    
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 1; j < (i + 1) * 2; j++) cout << "*";
        cout << "\n";
    }
    return 0;
}