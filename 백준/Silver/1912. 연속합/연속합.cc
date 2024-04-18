#include <bits/stdc++.h>
using namespace std;

int n, sum, ret = -1001;
int a[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        ret = max(ret, sum);
        if(sum < 0) sum = 0;
    }
    cout << ret;
    return 0;
}
