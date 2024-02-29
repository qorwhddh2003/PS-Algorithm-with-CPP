#include <bits/stdc++.h>
using namespace std;

int t, n;
bool flag;
string s, p, ret;
deque<int> dq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> p >> n >> s;
        flag = 0;
        int cur = -1, temp = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                temp = cur = temp * 10 + (s[i] - '0');
            }else if(cur != -1){
                dq.push_back(temp);
                cur = -1, temp = 0;
            }
        }
        
        int cnt = 0, reverse_flag = 0;
        for(char fn : p){
            if(fn == 'R') reverse_flag = (reverse_flag + 1) % 2;
            else if(fn == 'D'){
                if(dq.size() == 0) {flag = 1; break; }
                if(reverse_flag) dq.pop_back();
                else dq.pop_front();
            }
        }
        
        if(flag) ret = "error";
        else if(dq.size() == 0) {ret = "[]";}
        else{
            ret = "[";
            while(dq.size()){
                if(reverse_flag){
                    ret += to_string(dq.back());
                    dq.pop_back();
                }else{
                    ret += to_string(dq.front());
                    dq.pop_front();
                }
                ret += ",";
            }
            ret = ret.substr(0, ret.size() - 1);
            ret += "]";
        }
        cout << ret << "\n";
    }

    return 0;
}
