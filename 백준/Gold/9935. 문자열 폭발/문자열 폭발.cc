#include <bits/stdc++.h>
using namespace std;

string a, b;
stack<char> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    for(char ch : a){
        stk.push(ch);
        if(stk.size() >= b.size() && stk.top() == b[b.size() - 1]){
            string tempS = "";
            for(char c : b){
                tempS += stk.top(); stk.pop();
            }
            reverse(tempS.begin(), tempS.end());
            if(tempS != b){
                for(char c : tempS){
                    stk.push(c);
                }
            }
        }
    }
    
    if(stk.size()){
        string ret = "";
        while(stk.size()){
            ret += stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret;
    }else cout << "FRULA";
    return 0;
}
