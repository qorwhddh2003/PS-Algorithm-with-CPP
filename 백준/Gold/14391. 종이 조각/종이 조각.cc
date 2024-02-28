#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[4][4];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    for(int b = 0; b < (1 << 16); b++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                int k = i * m + j;
                if(b & (1 << k)){
                    sum += cur;
                    cur = 0;
                }else{
                    cur = cur * 10 + a[i][j];
                }
            }
            sum += cur;
        }
        for(int i = 0; i < m; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                int k = j * m + i;
                if(b & (1 << k)){
                    cur = cur * 10 + a[j][i];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret;
    return 0;
}