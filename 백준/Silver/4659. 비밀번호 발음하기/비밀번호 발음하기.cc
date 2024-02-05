#include <bits/stdc++.h>
using namespace std;

bool IsVowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s;
    while(true){
        cin >> s;
        if(s == "end") break;
        int vw_cnt = 0, con_cnt = 0, prev = -1;
        bool flag = 0, vw_flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(IsVowel(s[i])) vw_flag = 1, vw_cnt++, con_cnt = 0;
            else vw_cnt = 0, con_cnt++;
            if(vw_cnt == 3 || con_cnt == 3) flag = 1;
            if(i >= 1 && s[i] == s[prev] && (s[i] != 'e' && s[i] != 'o')) flag = 1;
            prev = i;
        }
        if(vw_flag == 0) flag = 1;
        if(flag) cout << "<"  << s << "> is not acceptable.\n";
        else cout << "<" << s << "> is acceptable.\n";
    }
    return 0;
}
