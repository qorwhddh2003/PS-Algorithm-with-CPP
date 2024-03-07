#include <bits/stdc++.h>
using namespace std;

int a, b;
map<int, int> xpos, ypos;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        xpos[a]++;
        ypos[b]++;
    }
    
    for(auto it : xpos){
        if(it.second == 1) cout << it.first;
    }
    cout << " ";
    for(auto it : ypos){
        if(it.second == 1) cout << it.first;
    }
    return 0;
}
