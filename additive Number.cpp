#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define SIZE(x) (int)x.size()
#define MP(x,y) make_pair(x,y)
#define ALL(t) (t).begin(),(t).end()
#define CLR(x,y) memset(x,y,sizeof(x))
#define FOR(i,n,m) for (int i = n; i <= m; i++)
#define ROF(i,n,m) for (int i = n; i >= m; i--)

#define RI(x) scanf ("%d", &(x))
#define RII(x,y) RI(x),RI(y)
#define RIII(x,y,z) RI(x),RI(y),RI(z)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const ll mod = 1e9 + 7;
const int seed = 105;
const double eps = 1e-8;

/***********************END OF DEFINE******************************/
/*
class Solution {
public:
    bool isValidSerialization(string preorder) {

    }
};

vector<string> split(string stext, string spatten) {
    vector<string> vec;
    char *p = strtok(text, patten);
    while(p) {
        vec.push_back(string(p));
        p = strtok(NULL, patten);
    }
    return vec;
}

char *stringToChar(string str) {
    char cstr[str.size()
    ];
    strcpy(cstr, str.c_str());
    return cstr;
}
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) return false;
        return dfs(0, 0, num);
    }
    bool dfs(int l1, int l2, string s) {
        int idx = canSum(s.substr(0, l1), s.substr(l1, l2), s.substr(l1 + l2));
        if(idx && l1 + l2 + idx == s.size()) {
            return true;
        }
        else if(idx) {
            if(canSum(s.substr(l1).substr(0, l2), s.substr(l1).substr(l2, idx), s.substr(l1).substr(l2 + idx)) && dfs(l2, idx, s.substr(l1)))
                return true;
        }
        else {
            for(int i = l1 ; i < s.size(); i++)
                for(int j = l2; j + i < s.size(); j++)
                    if(i != l1 || j != l2) {
                        if(canSum(s.substr(0, i), s.substr(i, j), s.substr(i + j)) && dfs(i, j, s))
                            return true;
                    }
        }
        return false;
    }
    int canSum(string s1, string s2, string s3) {
        if(s1 == "" || s2 == "" || s3 == "") return 0;
        else if(s1[0] == '0' && s1.size() > 1 || s2[0] == '0' && s2.size() > 1 || s3[0] == '0' && s3.size() > 1) return 0;
        for(int i = max(s1.size(), s2.size()) - 1; i < s3.size(); i++) {
            int tmp = judge(s1, s2, s3.substr(0, i + 1));
            if(tmp == 1)
                return i + 1;
            else if(tmp == 2)
                return 0;
        }
        return 0;
    }
    int judge(string s1, string s2, string s3) {
        stringstream ss1(s1), ss2(s2), ss3(s3);
        long long n1, n2, n3;
        ss1 >> n1; ss2 >> n2; ss3 >> n3;
        if(n1 + n2 == n3) return 1;
        else if(n1 + n2 < n3) return 2;
        else return 0;
    }
};


int main() {
    // freopen("data.out", "w", stdout);
    string s;
    Solution op;
    while(cin >> s) {
        cout << op.isAdditiveNumber(s) << endl;
    }
}
/*
    9,3,4,#,#,1,#,#,2,#,6,#,#
    9,3,4,7,8,1,2,4,2,5,6,6,7
*/
