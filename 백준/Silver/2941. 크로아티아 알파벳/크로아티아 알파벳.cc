#include <bits/stdc++.h>
using namespace std;

int ret;
string s;
string a[8] = {
    "dz=",
    "c=",
    "c-",
    "d-",
    "lj",
    "nj",
    "s=",
    "z="
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(i + 1 < s.size() || i + 2 < s.size()){
            for(int j = 0; j < 8; j++){
                if(s.substr(i, a[j].size()) == a[j]){
                    i += a[j].size() - 1;
                    break;
                }
            }
        }
        ret++;
    }
    cout << ret;
    return 0;
}
