#include <bits/stdc++.h>
using namespace std;

vector<int> ret[10];
int n, a[1024];
void go(int low, int high, int level){
    if(low > high) return;
    if(low == high){
        ret[level].push_back(a[low]);
        return;
    }
    int mid = (low + high) / 2;
    ret[level].push_back(a[mid]);
    go(low, mid - 1, level + 1);
    go(mid + 1, high, level + 1);
    return;
}

int main(){
    cin >> n;
    int _end = (int)pow(2, n) - 1;
    for(int i = 0; i < _end; i++){
        cin >> a[i];
    }
    go(0, _end, 1);
    for(int i = 1; i <= n; i++){
        for(int nd : ret[i]){
            cout << nd << " ";
        }
        cout << "\n";
    }
}
