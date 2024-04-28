#include <bits/stdc++.h>
using namespace std;

int T, N, M, target;
int a[1000000];

bool binarySearch(int target, int arr[]){
    int left = 0, right = N - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> a[i];
        cin >> M;
        sort(a, a + N);
        for(int i = 0; i < M; i++){
            cin >> target;
            cout << binarySearch(target, a) << "\n";
        }
    }
    
    return 0;
}