#include <bits/stdc++.h>
using namespace std;

int N, temp;
vector<int> v, vv;

void fastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main()
{
    fastIO();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        v.push_back(temp);
        vv.push_back(temp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i : vv){
        cout << lower_bound(v.begin(), v.end(), i) - v.begin() << " ";
    }
    return 0;
}
