#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1, room_no = 1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(true){
        if(n <= room_no) break;
        room_no += (6 * cnt);
        cnt++;
    }
    cout << cnt;
    return 0;
}
