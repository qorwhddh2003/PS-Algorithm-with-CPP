#include <bits/stdc++.h>
using namespace std;

int n, k;
int words[51];
string s;

int count(int mask){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((words[i] & mask) == words[i]) cnt++;
    }
    return cnt;
}

int go(int idx, int k, int mask){
    if(k < 0) return 0;
    if(idx == 26) return count(mask);
    int ret = go(idx + 1, k - 1, mask | (1 << idx));
    if(idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'c'-'a' && idx != 'i'-'a'){
        ret = max(ret, go(idx + 1, k, mask));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if(k < 5){cout << 0; return 0;}
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            words[i] |= (1 << (s[j] - 'a'));
        }
    }
    cout << go(0, k, 0);
    return 0;
}
