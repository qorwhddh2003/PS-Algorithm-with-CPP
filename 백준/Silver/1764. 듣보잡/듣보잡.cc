#include <bits/stdc++.h>
using namespace std;

int n, m;
string temp;
vector<string> vec;
map<string, bool> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> temp;
        mp[temp] = true;
    }
    for(int i = 0; i < m; i++){
        cin >> temp;
        if(mp[temp]){
            vec.push_back(temp);
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for(string s : vec){
        cout << s << "\n";
    }
    return 0;
}
