#include <bits/stdc++.h>
using namespace std;

int n, temp;
deque<pair<int, int>> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        dq.push_back({i + 1, temp});
    }
    
    int move, num;
    while(dq.size()){
        tie(num, move) = dq.front();
        dq.pop_front();
        cout << num << " ";
        
        move = (move > 0 ? move - 1 : move);
        while(move != 0){
            if(move > 0){
                dq.push_back(dq.front());
                dq.pop_front();
            }else{
                dq.push_front(dq.back());
                dq.pop_back();
            }
            move = (move > 0 ? --move : ++move);
        }
    }
    
    return 0;
}
