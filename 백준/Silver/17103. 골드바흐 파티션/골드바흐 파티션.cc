#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
int t, n;
bool isPrime[MAX];
vector<int> primeVec;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(isPrime, isPrime + MAX, 1);
    isPrime[1] = false;
    for(int i = 2; i * i < MAX; i++){
        if(!isPrime[i]) continue;
        for(int j = i * i; j < MAX; j += i){
            isPrime[j] = false;
        }
    }

    for(int i = 2; i < MAX; i++){
        if(isPrime[i]){
            primeVec.push_back(i);
        }
    }
    
    cin >> t;
    int vecSize = primeVec.size();
    while(t--){
        cin >> n;
        int ret = 0;
        int loop_cnt = (int)(lower_bound(primeVec.begin(), primeVec.end(), n) - primeVec.begin());
        for(int i = 0; i < loop_cnt; i++){
            if(primeVec[i] > n / 2) break;
            if(binary_search(primeVec.begin(), primeVec.end(), n - primeVec[i])){
                ret++;
            }
        }
        cout << ret << "\n";
    }
    
    return 0;
}
