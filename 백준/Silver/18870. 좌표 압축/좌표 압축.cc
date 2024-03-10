#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> vec1, vec2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        vec1.push_back(temp);
        vec2.push_back(temp);
    }
    sort(vec1.begin(), vec1.end());
    vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());
    
    for(int i = 0; i < n; i++){
        auto it = lower_bound(vec1.begin(), vec1.end(), vec2[i]);
        cout << it - vec1.begin() << " ";
    }
    
    return 0;
}
