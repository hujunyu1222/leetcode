#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool judge(string s) {
    for (int i = 0, j = (int)s.size() - 1; i <= j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int ret = 0;
        string tmp = "";
        for (int i = 0; i < s1.size(); i++) {
            tmp = s1.substr(0, i) + s2 + s1.substr(i);
            if (judge(tmp))
                ret ++;
        }
        cout << ret << endl;
    }
    return 0;
}
