#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> vec;
map<string, int> mp;

bool cmp(const string &a, const string &b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(mp[s] == 0){
            vec.push_back(s);
            mp[s]++;
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    for(string a : vec){
        cout << a << "\n";
    }
    
    return 0;
}