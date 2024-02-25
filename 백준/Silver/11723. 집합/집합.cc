#include <bits/stdc++.h>
using namespace std;

int n;
int mask;
string s;

vector<string> split(const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i <= n; i++){
        getline(cin, s);
        vector<string> v = split(s, " ");
        if(v[0] == "add"){
            mask |= (1 << (stoi(v[1]) - 1));
        }else if(v[0] == "remove"){
            mask &= ~(1 << (stoi(v[1]) - 1));
        }else if(v[0] == "check"){
            if(mask & (1 << stoi(v[1]) - 1)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if(v[0] == "toggle"){
            if(mask & (1 << stoi(v[1]) - 1)) mask &= ~(1 << (stoi(v[1]) - 1));
            else mask |= (1 << (stoi(v[1]) - 1));
        }else if(v[0] == "all"){
            for(int j = 0; j < 20 ; j++){
                mask |= (1 << j);
            }
        }else if(v[0] == "empty"){
            mask = 0;
        }
    }
    
    return 0;
}
