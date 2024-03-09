#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(char ch : s){
        v.push_back(ch - '0');
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i : v){
        cout << i;
    }
    return 0;
}
