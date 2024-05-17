#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
#define INF 1e9 + 4

int N, len;
int num[MAX_N], a[MAX_N], prev_list[MAX_N];
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    fill(a, a + MAX_N, INF);
    for(int i = 0; i < N; i++){
        cin >> num[i];
        auto lowerPos = lower_bound(a, a + len, num[i]);
        if(*lowerPos == INF) len++;
        *lowerPos = num[i];
        prev_list[i] = lowerPos - a;
    }
    
    cout << len << "\n";
    for(int i = N - 1; i >= 0; i--){
        if(prev_list[i] == len - 1){
            stk.push(i);
            len--;
        }
    }
    
    while(stk.size()){
        cout << num[stk.top()] << " ";
        stk.pop();
    }
    
    return 0;
}
