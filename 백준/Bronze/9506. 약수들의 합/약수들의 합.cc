#include <bits/stdc++.h>
using namespace std;

int n, k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> v;
    while(cin >> n){
        if(n == -1) break;
        int sum = 0;
        v.clear();
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                v.push_back(i);
                sum += i;
            }
            if(sum > n){
                v.clear();
                break;
            }
        }
        if(v.size() && sum == n){
            string ret;
           for(int i = 0; i < v.size(); i++){
               ret += to_string(v[i]);
               if(i < v.size() - 1) ret += " + ";
           }
           cout << n << " = " << ret << "\n";
        }else{
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}