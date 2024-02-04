#include <bits/stdc++.h>
using namespace std;

int h, w;
string s;
int a[100][100];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        bool cloud_flag = 0;
        for(int j = 0; j < w; j++){
            if(s[j] == 'c'){
                cloud_flag = 1;
                a[i][j] = 0;
            }else if(s[j] == '.'){
                if(cloud_flag) a[i][j] = a[i][j - 1] + 1;
                else a[i][j] = -1;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}