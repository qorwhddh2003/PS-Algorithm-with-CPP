#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 9e8

vector<int> changeList(vector<int> weak, int start, int n){
    if(start == 0) return weak;
    vector<int> list;
    for(int i = start; i < weak.size(); i++) list.push_back(weak[i]);
    for(int i = 0; i < start; i++) list.push_back(weak[i] + n);
    return list;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INF;
    for(int k = 0; k < weak.size(); k++){
        vector<int> weak_list = changeList(weak, k, n);        
        do{
            bool flag = true;
            int cnt = 0;
            int cur = weak_list[0] + dist[cnt];
            for(int i = 1; i < weak_list.size(); i++){
                if(cur < weak_list[i]){
                    if(cnt + 1 == dist.size()){
                        flag = false;
                        break;
                    }
                    cur = weak_list[i] + dist[++cnt];
                }
            }
            if(flag) answer = min(answer, cnt + 1);
        }while(next_permutation(dist.begin(), dist.end()));
    }
    return (answer == INF ? -1 : answer);
}