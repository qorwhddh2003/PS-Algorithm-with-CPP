#include <bits/stdc++.h>
using namespace std;

int n;
int y, x;
vector<pair<int, int>> vec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> y >> x;
        vec.push_back({y, x});
    }
    sort(vec.begin(), vec.end());
    
    for(pair<int, int> p : vec){
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}