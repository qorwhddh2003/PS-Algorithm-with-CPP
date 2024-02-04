#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
    while(cin >> s){
        if(s == "end") break;
        int vw_cnt = 0, con_cnt = 0, idx = 0;
        bool vw_flag = 0, ret_flag = 1;
        
        do{
            char temp = s[idx];
            switch(temp){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u': {
                    vw_cnt++;
                    con_cnt = 0;
                    vw_flag = 1;
                    break;
                }
                default: {
                    vw_cnt = 0;
                    con_cnt++;
                }
            }
            
            if(vw_cnt == 3 || con_cnt == 3){
                ret_flag = 0;
                break;
            }else if(idx + 1 <= s.size()-1){
                if(temp == s[idx + 1]){
                    if(temp == 'e' || temp == 'o'){
                        idx++;
                        continue;
                    }
                    ret_flag = 0;
                    break;
                }
            }
            
            idx++;
        }while(idx < s.size());
        if(vw_flag == 0) ret_flag = 0;
        if(ret_flag) cout << "<" << s << "> is acceptable.\n";
        else cout << "<" << s << "> is not acceptable.\n";
    }
    
    return 0;
}