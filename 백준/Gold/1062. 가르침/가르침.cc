#include <bits/stdc++.h>
using namespace std;

int n, k, ret, aaa;
int words[51];
string s;

int count(int mask){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((words[i] & mask) == words[i]) cnt++;
    }
    return cnt;
}

int go(int index, int k, int mask){
    aaa++;
    if(k < 0) return 0;
    if(index == 26) return count(mask);
    int ret = go(index+1, k-1, mask | (1 << index));
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        ret = max(ret, go(index + 1, k, mask));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            words[i] |= (1 << (s[j] - 'a'));
        }
    }
    cout << go(0, k, 0);
    return 0;
}
