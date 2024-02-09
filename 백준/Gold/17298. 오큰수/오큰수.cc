#include <bits/stdc++.h>
using namespace std;

int N, temp[1000001], ret[1000001];
stack<int> stk;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < N; i++){
        cin >> temp[i];
        while(stk.size() && temp[stk.top()] < temp[i]){
            ret[stk.top()] = temp[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 0; i < N; i++) cout << ret[i] << " ";
    return 0;
}