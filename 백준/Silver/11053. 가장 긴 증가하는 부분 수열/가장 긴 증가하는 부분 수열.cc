#include <bits/stdc++.h>
using namespace std;

int N;
int a[1001], cnt[1001], ret;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < N; i++){
        int idx = 0;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && cnt[j] > idx) idx++;
        }
        cnt[i] = idx + 1;
        ret = max(ret, cnt[i]);
    }
    
    cout << ret;
    return 0;
}