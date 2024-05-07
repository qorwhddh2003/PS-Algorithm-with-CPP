#include <bits/stdc++.h>
using namespace std;

int N, M, lo = 1, hi, mx, ret;
int a[100000];

bool check(int mid){
    int cnt = 1, temp = mid;
    for(int i = 0; i < N; i++){
        if(mid - a[i] < 0){
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    return cnt <= M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        hi += a[i];
        mx = max(mx, a[i]);
    }
    lo = mx, hi = 1000000000;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ret = mid;
            hi = mid - 1;
        }else lo = mid + 1;
    }
    cout << ret;
    return 0;
}