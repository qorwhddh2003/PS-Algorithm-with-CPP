#include <bits/stdc++.h>
using namespace std;

int N, s, e;
double ret, ans;
double a[10000];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++){
        ans = a[i];
        ret = max(ret, ans);
        for(int j = i + 1; j < N; j++){
            ans *= a[j];
            ret = max(ret, ans);
        }
    }
        
    printf("%.3lf", ret);
    return 0;
}
