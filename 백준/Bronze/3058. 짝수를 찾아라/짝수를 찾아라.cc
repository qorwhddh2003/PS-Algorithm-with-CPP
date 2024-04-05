#include <bits/stdc++.h>
using namespace std;

int T, temp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    
    while(T--){
        int mn_num = 9e8, even_sum = 0;
        vector<int> v;
        for(int i = 0; i < 7; i++){
            cin >> temp;
            v.push_back(temp);
        }
        
        for(int i : v){
            if(i % 2 == 0){
                mn_num = min(mn_num, i);
                even_sum += i;
            }
        }
        
        cout << even_sum << " " << mn_num << "\n";
    }
    
    return 0;
}