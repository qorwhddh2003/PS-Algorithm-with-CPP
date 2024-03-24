#include <bits/stdc++.h>
using namespace std;

int n, x, ret;
vector<int> v(100000);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.begin() + n);
    int left = 0, right = n - 1;
    while(left < right){
        int sum = v[left] + v[right];
        if(sum > x) right--;
        else if(sum < x) left++;
        else if(sum == x) ret++, left++, right--;
    }
    cout << ret;
    return 0;
}
