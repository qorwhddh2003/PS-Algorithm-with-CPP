#include <bits/stdc++.h>
using namespace std;

int N;
double ret, ans;
double a[10000];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    
    ret = ans = a[0];
    for(int i = 1; i < N; i++){
        if(a[i] > ans * a[i]) ans = a[i];
        else ans *= a[i];
        ret = max(ret, ans);
    }
    
    printf("%.3lf", ret);
    return 0;
}