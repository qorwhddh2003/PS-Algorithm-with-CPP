#include <bits/stdc++.h>
using namespace std;

int a[9];
void printV(vector<int> v){
    for(int i : v) cout << i << '\n';
}

void combi(int start, vector<int> &b){
    if(b.size() == 7){
        int sum = accumulate(b.begin(), b.end(), 0);
        if(sum == 100){
            printV(b);
            exit(0);
        }
    }
    
    for(int i = start+1; i < 9; i++){
        b.push_back(a[i]);
        combi(i, b);
        b.pop_back();
    }
    
    return;
}

int main(){
    for(int i = 0; i < 9; i++) cin >> a[i];
    sort(a, a+9);
    vector<int> v;
    combi(-1, v);
    return 0;
}