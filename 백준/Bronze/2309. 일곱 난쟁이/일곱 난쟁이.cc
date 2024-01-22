#include <bits/stdc++.h>
using namespace std;

int val;
vector<int> dwarf;
int main(){
    for(int i = 0; i < 9; i++){
        cin >> val;
        dwarf.push_back(val);
    }
    sort(dwarf.begin(), dwarf.end());
    
    do{
        int sum = accumulate(dwarf.begin(), dwarf.begin() + 7, 0);
        if(sum == 100) break;
    }while(next_permutation(dwarf.begin(), dwarf.end()));
    
    for(int i = 0; i < 7; i++) cout << dwarf[i] << '\n';
    
    return 0;
}