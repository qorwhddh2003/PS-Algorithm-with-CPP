#include <bits/stdc++.h>
using namespace std;

int n, sum;
int a[5];
int main()
{
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }
    sort(a, a + 5);
    for(int i = 0; i < 5; i++){
        sum += a[i];   
    }
    cout << sum / 5 << "\n" << a[2];
    return 0;
}
