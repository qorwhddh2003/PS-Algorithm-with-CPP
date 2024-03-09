#include <bits/stdc++.h>
using namespace std;

int n, a;
string s;
struct Info {
    int id;
    int age;
    string name;
};
vector<Info> vec;

bool cmp(Info a, Info b){
    if(a.age == b.age) return a.id < b.id;
    return a.age < b.age;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        vec.push_back({i, a, s});
    }
    sort(vec.begin(), vec.end(), cmp);
    for(Info i : vec){
        cout << i.age << " " << i.name << "\n";
    }
    return 0;
}