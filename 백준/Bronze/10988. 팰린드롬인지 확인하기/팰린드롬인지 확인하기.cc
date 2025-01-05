#include <bits/stdc++.h>
using namespace std;

string str, rev_str;

int main()
{
    cin >> str;
    rev_str =str;
    reverse(rev_str.begin(), rev_str.end());
    cout << (str == rev_str);
    return 0;
}