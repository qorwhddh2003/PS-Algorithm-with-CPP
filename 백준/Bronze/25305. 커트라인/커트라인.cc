#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    cout << a[k - 1];
    return 0;
}
