#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> names;
set<string> offBrand;
string name;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> name;
        names.insert(name);
    }
    for(int i = 0; i < m; i++){
        cin >> name;
        if(names.find(name) != names.end()){
            offBrand.insert(name);
        }
    }
    
    cout << offBrand.size() << "\n";
    for(string s : offBrand){
        cout << s << "\n"; 
    }
    
    return 0;
}
