#include <bits/stdc++.h>
using namespace std;

int cnt[101];
int A, B, C, arrive, leave, fee;
int main(){
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++){
        cin >> arrive >> leave;
        for(int j = arrive; j < leave; j++) cnt[j]++;
    }
    for(int i = 1; i <= 100; i++){
        if(cnt[i] == 1) fee += A;
        else if(cnt[i] == 2) fee += B * 2;
        else if(cnt[i] == 3) fee += C * 3;
    }
    cout << fee;
    
    return 0;
}