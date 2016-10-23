#include <iostream>
#include <string>
#include <vector>
using namespace std;

//O(n)回文子串（Manacher）算法
//先将原始字符串中插入“#”，使其子串都是奇数
//P[i]用于存储最大回文子串长度
string findPstr(const string &str){
    int n = str.size();
    string res;
    vector<int> P(n+1);
    int id, mx;
    int i;
    id = mx = 0;
    P[0] = 0;


    for (i = 1; i < n; i++){
        //精髓的if-else分支
        if (mx > i){
            P[i] = (P[id*2 - i] > mx - i ? mx - i : P[id*2 - i]);
        }
        else{
            P[i] = 1;
        }

        //寻找回文串
        while (str[i - P[i]] == str[i + P[i]]){
            P[i]++;
        }
        //cout << P[i] << "i:" << i << endl;

        if (i + P[i] > mx ){
            mx = i + P[i];
            id = i;
        }

    }
    int index = 0;
    int max = -1;
    for (i = 1; i < n; i++){
        if (P[i] > max){
            max = P[i];
            index = i;
        }
    }
    max --;
    int startS = index - max;
    int endS = index + max;
    for (i = startS;i <= endS; i++){
        if (str[i]!='#')
        {
            res+= str[i];
        }
    }
    return res;
}

int main(){

    string s;
    string temp;
    string pSubs;
    int i;
    int n;

    cin >> s;
    n = s.size();
    temp +='$';
    for (i=0;i<n;i++){
        temp += '#';
        temp +=s[i];
    }
    temp += '#';
    cout <<temp << endl;

    pSubs = findPstr(temp);
    cout << pSubs;



    return 0;
}
