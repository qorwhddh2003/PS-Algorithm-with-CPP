#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
map<int, string> mp;
map<string, int> mp2;

int main()
{  
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s;
        mp[i + 1] = s;
        mp2[s] = i + 1;
    }
    
    for(int i = 0; i < M; i++){
        cin >> s;
        if(atoi(s.c_str()) == 0) cout << mp2[s];
        else cout << mp[atoi(s.c_str())];
        cout << "\n";
    }
    
    
    return 0;
}