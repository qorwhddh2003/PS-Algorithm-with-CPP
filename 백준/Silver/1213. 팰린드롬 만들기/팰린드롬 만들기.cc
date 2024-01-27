#include <bits/stdc++.h>
using namespace std;

int flag;
int arr[26];
char mid;
string ret, s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    
    for(char c : s) arr[c - 'A']++;
    for(int i = 'Z'; i >= 'A'; i--){
        if(arr[i - 'A'] & 1){
            arr[i - 'A']--;
            mid = char(i);
            flag++;
        }
        if(flag == 2) break;
        for(int j = 0; j < arr[i - 'A']; j += 2){
           ret =  char(i) + ret;
           ret += char(i);
        }
    }
    
    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo";
    else cout << ret;
    
}