#include <bits/stdc++.h>
using namespace std;

int N, ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 1; i * i <= N; i++){
        ret++;
    }
    cout << ret;
    return 0;
}
