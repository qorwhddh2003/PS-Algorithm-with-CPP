#include <bits/stdc++.h>
using namespace std;

string n, str;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int len = n.size();
    
    for(int i = stoi(n) - 9 * len; i <= stoi(n); i++){
        
        int num = i;
        str = to_string(i);
        for(int j = 0; j < str.size(); j++){
            num += str[j] - '0';
        }
        
        if(num == stoi(n)){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}