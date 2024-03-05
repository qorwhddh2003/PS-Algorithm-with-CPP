#include <bits/stdc++.h>
using namespace std;

int n, a, b, ret;
int visited[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int k = 0; k < n; k++){
        cin >> a >> b;
        
        for(int i = a; i < a + 10; i++){
            for(int j = b; j < b + 10; j++){
                if(visited[i][j]) continue;
                visited[i][j] = 1;
                ret++;
            }
        }
    }
    cout << ret;
    cout << "\n";
    return 0;
}
