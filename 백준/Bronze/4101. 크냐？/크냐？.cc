#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cout << (n > m ? "Yes\n" : "No\n");
    }
    return 0;
}
