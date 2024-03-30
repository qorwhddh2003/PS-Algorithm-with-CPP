#include <iostream>
using namespace std;

int A, B, C;
int cnt[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;
    string s = to_string(A * B * C);
    for(char ch : s){
        cnt[ch - '0']++;
    }
    
    for(int i = 0; i < 10; i++){
        cout << cnt[i] << "\n";
    }
    return 0;
}