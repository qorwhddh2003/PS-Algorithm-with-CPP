#include <bits/stdc++.h>
using namespace std;

struct A{
    int r, c, s;
};

const int MAX = 50;
int N, M, K, ret = 9e8;
int a[MAX][MAX];
vector<A> v;
vector<int> idx;

void rotate(A rcs, int arr[MAX][MAX]){
    for(int layer = 1; layer <= rcs.s; layer++){
        int top = rcs.r - layer;
        int bottom = rcs.r + layer;
        int left = rcs.c - layer;
        int right = rcs.c + layer;
        
        int prev = arr[top][left];
        for(int i = left + 1; i <= right; i++) swap(arr[top][i], prev);
        for(int i = top + 1; i <= bottom; i++) swap(arr[i][right], prev);
        for(int i = right - 1; i >= left; i--) swap(arr[bottom][i], prev);
        for(int i = bottom - 1; i >= top; i--) swap(arr[i][left], prev);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a[i][j];
        }
    }
    
    A temp;
    for(int i = 0; i < K; i++){
        cin >> temp.r >> temp.c >> temp.s;
        temp.r--, temp.c--;
        v.push_back(temp);
        idx.push_back(i);
    }
    
    do{
        int temp_arr[MAX][MAX];
        memcpy(temp_arr, a, sizeof(a));
        for(int i : idx){
            rotate(v[i], temp_arr);
        }
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = 0; j < M; j++){
                sum += temp_arr[i][j];
            }
            ret = min(ret, sum);
        }
    }while(next_permutation(idx.begin(), idx.end()));
    
    cout << ret;
    return 0;
}
