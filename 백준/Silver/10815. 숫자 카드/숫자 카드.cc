#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
map<int, bool> card;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        card[temp] = true;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(card[temp]){
            cout << 1 << " ";
        }else{
            cout << 0 << " ";
        }
    }
    
    return 0;
}
