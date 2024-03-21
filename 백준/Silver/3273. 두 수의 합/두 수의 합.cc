#include <bits/stdc++.h>
using namespace std;

int n, x, temp, ret;
vector<int> vec;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    cin >> x;
    sort(vec.begin(), vec.end());
    
    int left = 0, right = vec.size() - 1;
    while(left < right){
        if(vec[left] + vec[right] > x) right--;
        else if(vec[left] + vec[right] < x) left++;
        else left++, right--, ret++;
    }
    cout << ret;
    return 0;
}
