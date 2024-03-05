#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
int n, l, ret;
int road[MAX][MAX], rotate_road[MAX][MAX];

void go(int a[MAX][MAX]){
    for(int i = 0; i < n; i++){
        int j = 0, cnt = 1;
        for(j = 0; j < n - 1; j++){
            if(a[i][j] == a[i][j + 1]) cnt++;
            else if(a[i][j] + 1 == a[i][j + 1] && cnt >= l) cnt = 1;
            else if(a[i][j] == a[i][j + 1] + 1 && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if(j == n - 1 && cnt >= 0) ret++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> road[i][j];
            rotate_road[j][i] = road[i][j];
        }
    }
    go(road);
    go(rotate_road);
    cout << ret;
    return 0;
}
