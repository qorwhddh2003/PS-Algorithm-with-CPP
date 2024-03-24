#include <bits/stdc++.h>
using namespace std;

const int MAX = 4e6 + 1;
int n, s, e, ret;
vector<int> prime_numbers;
bool is_prime[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 2; i * i < MAX; i++){
        if(is_prime[i]) continue;
        for(int j = i * i; j < MAX; j += i){
            is_prime[j] = true;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(is_prime[i]) continue;
        prime_numbers.push_back(i);
    }
    
    int sum = 0;
    while(s < prime_numbers.size()){
        if(sum >= n || e == prime_numbers.size()) sum -= prime_numbers[s++];
        else sum += prime_numbers[e++];
        if(sum == n) ret++;
    }
    cout << ret;
    return 0;
}
