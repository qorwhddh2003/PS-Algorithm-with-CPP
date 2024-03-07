#include <bits/stdc++.h>
using namespace std;

int a[3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << a[0] + a[1] + min(a[0] + a[1] - 1, a[2]);
    return 0;
}
