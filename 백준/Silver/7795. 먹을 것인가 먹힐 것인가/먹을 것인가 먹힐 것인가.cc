#include <bits/stdc++.h>
using namespace std;

int T, N, M, lo, hi;
int a[20001], b[20001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        int ret = 0;
        for(int i = 1; i <= N; i++) cin >> a[i];
        for(int i = 1; i <= M; i++) cin >> b[i];
        sort(b + 1, b + M + 1);
        
        for(int i = 1; i <= N; i++){
            lo = 0, hi = M;
            int mid;
            while(lo <= hi){
                mid = (lo + hi) / 2;
                if(b[mid] < a[i]) lo = mid + 1;
                else hi = mid - 1;
            }
            if(b[mid] >= a[i]) mid--;
            ret += mid;
        }
        cout << ret << "\n";
    }

    return 0;
}
