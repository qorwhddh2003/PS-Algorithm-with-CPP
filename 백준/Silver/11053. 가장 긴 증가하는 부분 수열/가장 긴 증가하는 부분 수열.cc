#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000

int N, num, ret;
int a[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        auto lower_pos = lower_bound(a, a + ret, num);
        if(*lower_pos == 0) ret++;
        *lower_pos = num;
    }
    
    cout << ret;
    return 0;
}
