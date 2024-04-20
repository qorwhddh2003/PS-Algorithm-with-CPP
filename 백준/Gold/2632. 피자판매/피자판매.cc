#include <bits/stdc++.h>
using namespace std;

int a[1001], b[1001], psum_a[2002], psum_b[2002], N, M, target, ret;
map<int, int> aCnt, bCnt;

void make(int size, int psum[], map<int, int> &mp){
    for(int interval = 1; interval <= size; interval++){
        for(int start = interval; start <= size + interval - 1; start++){
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if(interval == size) break;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> target >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }
    for(int i = N + 1; i <= 2 * N; i++) psum_a[i] = psum_a[i - 1] + a[i - N];
    for(int i = 1; i <= M; i++){
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }
    for(int i = M + 1; i <= 2 * M; i++) psum_b[i] = psum_b[i - 1] + b[i - M];
    make(N, psum_a, aCnt);
    make(M, psum_b, bCnt);
    ret = aCnt[target] + bCnt[target];
    for(int i = 1; i < target; i++){
        ret += (aCnt[i] * bCnt[target - i]);
    }
    cout << ret;
    return 0;
}