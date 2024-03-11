#include <bits/stdc++.h>
using namespace std;
#define prev aaaa

int n, temp;
vector<int> v1;
vector<int> v2;
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
    sort(v1.begin(), v1.end());
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    for(int i = 0; i < n; i++){
        cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << " ";
    }
    return 0;
}