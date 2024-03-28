#include <bits/stdc++.h>
using namespace std;

int N, K, ret;
int a[100], visited[101];
vector<int> plug;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i < N; i++){
        if(visited[a[i]]) continue;
        if(plug.size() == K){
            int last_idx = 0, pos;
            for(int num : plug){
                int pick = 9e8;
                for(int j = i + 1; j < N; j++){
                    if(a[j]== num){
                        pick = j;
                        break;
                    }
                }
                
                if(last_idx < pick){
                    last_idx = pick;
                    pos = num;
                }
            }
            
            plug.erase(find(plug.begin(), plug.end(), pos));
            visited[pos] = 0;
            ret++;
        }
        plug.push_back(a[i]);
        visited[a[i]] = 1;
    }
    
    cout << ret;
    return 0;
}
