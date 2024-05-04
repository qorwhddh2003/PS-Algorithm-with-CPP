#include <bits/stdc++.h>
using namespace std;

int N, M, ret = 9e8;
int a[100001];

bool check(int tape_size){
    int cnt = M, sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(a[i] > tape_size) return false;
        if(sum > tape_size){
            sum = a[i]; 
            cnt--;
        }
    }
    if(sum > tape_size) cnt--;
    return cnt > 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int left = 1, right = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        right += a[i];
    }
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(mid)){
            ret = min(ret, mid);
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    cout << ret;
    return 0;
}