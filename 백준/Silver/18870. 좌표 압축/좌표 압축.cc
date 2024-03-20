#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v1, v2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        v1.push_back(temp);
        v2.push_back(temp);
    }
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i = 0; i < n; i++){
        cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << " ";
    }
    return 0;
}
