#include <bits/stdc++.h>
using namespace std;

int T, N;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        int five_cnt = 0;
        for(int i = 5; i <= N; i *= 5){
            five_cnt += N / i;
        }
        cout << five_cnt << "\n";
    }
    return 0;
}