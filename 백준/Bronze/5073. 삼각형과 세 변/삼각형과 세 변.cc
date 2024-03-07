#include <bits/stdc++.h>
using namespace std;

int a[3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(cin >> a[0] >> a[1] >> a[2]){
        if(a[0] + a[1] + a[2] == 0) break;
        sort(a, a + 3);
        if(a[2] < a[0] + a[1]){
            if(a[0] == a[1] && a[1] == a[2]) cout << "Equilateral\n";
            else if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }else{
            cout << "Invalid\n";
        }
    }
    return 0;
}
