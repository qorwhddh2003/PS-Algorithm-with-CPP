#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string str;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    
    cin >> str;
    for(char c : str){
        cnt[c - 'a']++;
    }
    for(int i : cnt) cout << i << " ";
    
    return 0;
}