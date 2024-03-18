#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000001;
int N;
bool is_prime[MAX];

bool check(string str){
    for(int i = 0; i < str.size() / 2; i++){
        if(str[i] != str[str.size() - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    is_prime[1] = true;
    for(int i = 2; i * i <= MAX; i++){
        if(is_prime[i]) continue;
        for(int j = i * i; j <= MAX; j += i){
            is_prime[j] = true; 
        }
    }
    
    for(int i = N; i <= MAX; i++){
        if(is_prime[i]) continue;
        if(check(to_string(i))){
            cout << i;
            break;
        }
    }
    
    return 0;
}