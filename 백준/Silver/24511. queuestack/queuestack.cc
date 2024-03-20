#include <bits/stdc++.h>
using namespace std;

int N, A, B, M, C;
int types[100001];
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> types[i];
    }
    
    for(int i = 0; i < N; i++){
        cin >> B;
        if(types[i]) continue;
        dq.push_front(B);
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> C;
        dq.push_back(C);
    }
    
    for(int i = 0; i < M; i++){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    
    return 0;
}
