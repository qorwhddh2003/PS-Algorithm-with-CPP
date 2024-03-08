#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c >> d >> e >> f;
    int x = (c * e - b * f) / (a * e - b * d);
    int y = (d * c - a * f) / (b * d - a * e);
    cout << x << " " << y;
    return 0;
}