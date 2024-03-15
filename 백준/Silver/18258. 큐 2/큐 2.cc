#include <bits/stdc++.h>
using namespace std;

int t, x;
string s;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> s;
        if(s == "push"){
            cin >> x;
            dq.push_back(x);
        }else if(s == "pop"){
            if(dq.size()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }else{
                cout << -1 << "\n";
            }
        }else if(s == "size"){
            cout << dq.size() << "\n";
        }else if(s == "empty"){
            cout << dq.empty() << "\n";
        }else if(s == "front"){
            if(dq.empty()){
                cout << -1 << "\n";
            }else{
                cout << dq.front() << "\n";
            }
        }else if(s == "back"){
            if(dq.empty()){
                cout << -1 << "\n";
            }else{
                cout << dq.back() << "\n";
            }   
        }
    }

    return 0;
}
