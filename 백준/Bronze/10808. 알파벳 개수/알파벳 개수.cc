#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string str;
int main(){
    cin >> str;
    for(char c : str){
        cnt[c - 'a']++;
    }
    
    for(int i : cnt) cout << i << " ";
}