#include <bits/stdc++.h>
using namespace std;

int n;
float temp;
vector<float> ret;
priority_queue<float> pq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        pq.push(temp);
        if(pq.size() == 8){
            pq.pop();
        }
    }
    
    for(int i = 0; i < 7; i++){
        ret.push_back(pq.top());
        pq.pop();
    }
    
    sort(ret.begin(), ret.end());
    for(int i = 0; i < ret.size(); i++){
        printf("%.3lf\n", ret[i]);
    }
    
    return 0;
}
