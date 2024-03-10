#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j <= s.size() - i; j++){
            string key = s.substr(j, i);
            ret.insert(key);
        }
    }
    cout << ret.size();
    return 0;
}