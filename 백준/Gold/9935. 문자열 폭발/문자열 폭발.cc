#include <bits/stdc++.h>
using namespace std;


string str, remove_str, ret;
stack<char> stk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str >> remove_str;
    for(int i = 0; i < str.size(); i++){
        stk.push(str[i]);
        if(stk.size() >= remove_str.size() && stk.top() == remove_str[remove_str.size() - 1]){
            string temp = "";
            for(int j = 0; j < remove_str.size(); j++){
                temp += stk.top();
                stk.pop();
            }
            reverse(temp.begin(), temp.end());
            
            if(temp != remove_str){
                for(char ch : temp){
                    stk.push(ch);
                }
            }
        }
    }
    
    while(stk.size()){
        ret += stk.top(); 
        stk.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << (ret.size() ? ret : "FRULA");
    return 0;
}
