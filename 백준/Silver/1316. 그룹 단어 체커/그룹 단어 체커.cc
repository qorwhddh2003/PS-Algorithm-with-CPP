#include <bits/stdc++.h>
using namespace std;

int n, ret, flag[26];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        fill(flag, flag + 26, 0);
        int prev = 0;
        bool check = 1;
        for(int j = 1; j < s.size(); j++){
            if(s[prev] != s[j] && flag[s[prev] - 'a'] == 0) flag[s[prev] - 'a'] = 1;
            else if(flag[s[prev] - 'a']) {check = 0; break;}
            prev = j;
        }
        if(flag[s[prev] - 'a']) check = 0;
        if(check) ret++;
    }
    
    cout << ret;
    return 0;
}