#include <bits/stdc++.h>
using namespace std;

int n, a, b, mxA = -9e8, mxB = -9e8, mnA = 9e8, mnB = 9e8;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        mxA = max(a, mxA);
        mxB = max(b, mxB);
        mnA = min(a, mnA);
        mnB = min(b, mnB);
    }
    cout << abs(mxA - mnA) * abs(mxB - mnB);
    return 0;
}
