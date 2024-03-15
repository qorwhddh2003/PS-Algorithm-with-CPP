#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    
    int cnt = 1;
    cout << "<";
    while(q.size()){
        if(cnt == k){
            cout << q.front();
            q.pop();
            if(q.size()) cout << ", ";
            cnt = 1;
            continue;
        }
        q.push(q.front());
        q.pop();
        cnt++;
    }
    cout << ">" << "\n";
    return 0;
}
