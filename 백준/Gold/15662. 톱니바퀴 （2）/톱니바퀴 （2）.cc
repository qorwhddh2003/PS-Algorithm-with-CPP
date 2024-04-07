#include <bits/stdc++.h>
using namespace std;

int T, K, temp, target, dir, ret;
vector<int> gear[1001];
int visited[1001];

int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        for(int j = 0; j < 8; j++){
            scanf("%1d", &temp);
            gear[i].push_back(temp);
        }
    }
    cin >> K;
    while(K--){
        cin >> target >> dir;
        fill(visited, visited + 1001, 0);
        visited[target] = dir;
        
        for(int i = target; i >= 2; i--){
            if(gear[i][6] != gear[i - 1][2]) visited[i - 1] = visited[i] * -1;
            else break;
        }
        
        for(int i = target; i < T; i++){
            if(gear[i][2] != gear[i + 1][6]) visited[i + 1] = visited[i] * -1;
            else break;
        }
        
        for(int i = 1; i <= T; i++){
            if(visited[i] == 1){
                rotate(gear[i].rbegin(), gear[i].rbegin() + 1, gear[i].rend());
            }else if(visited[i] == -1){
                rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
            }
        }
        
    }
    
    for(int i = 1; i <= T; i++){
        if(gear[i][0] == 1) ret++;
    }
    
    cout << ret;
    return 0;
}