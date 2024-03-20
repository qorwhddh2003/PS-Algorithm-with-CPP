#include <bits/stdc++.h>
using namespace std;

int n;
float temp;
priority_queue<float> pq;
vector<float> ret;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(pq.size() == 7){
            pq.push(temp);
            pq.pop();
        }else pq.push(temp);
    }
    
    for(int i = 0; i < 7; i++){
        ret.push_back(pq.top()); pq.pop();
    }
    
    for(int i = 0; i < 7; i++){
        printf("%.3lf\n", ret[7 - i - 1]);
    }

    return 0;
}
