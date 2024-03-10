#include <bits/stdc++.h>
using namespace std;

int n;
string name, status;
map<string, bool> mp;
vector<string> ret;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> status;
        mp[name] = (status == "enter");
    }
    
    for(auto it : mp){
        if(it.second){
            ret.push_back(it.first);
        }
    }
    sort(ret.begin(), ret.end(), greater<string>());
    for(string s : ret){
        cout << s << "\n";
    }
    return 0;
}
