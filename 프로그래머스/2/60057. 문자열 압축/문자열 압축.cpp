#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 9e8;    
    for(int sep = 1; sep <= s.size() / 2 + 1; sep++){
        int start = 0;
        vector<string> v;
        while(start < s.size()){
            v.push_back(s.substr(start, sep));
            start += sep;
        }
        
        int cnt = 1, ret = 0;
        string prev = v[0];
        for(int i = 1; i < v.size(); i++){
            if(prev == v[i]) cnt++;
            else{
                ret += (cnt == 1 ? 0 : to_string(cnt).size()) + prev.size();
                cnt = 1;
            }
            prev = v[i];
        }        
        ret += (cnt == 1 ? 0 : to_string(cnt).size()) + prev.size();
        answer = min(answer, ret);
    }
    return answer;
}