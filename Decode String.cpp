#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string process(string s, int &i){
    string res = "";

    while(i < s.size() && s[i] != ']'){
        if (!isdigit(s[i])){
            res += s[i++];
        }
        else{
            int n = 0;
            while(i < s.size() && isdigit(s[i])){
                n = n *10 + (s[i++] - '0');
            }

            i++;//'['
            string tmp = process(s, i);
            i++;//']';

            while(n != 0){
                if (n & 1 != 0){
                    res += tmp;
                }
                tmp = tmp + tmp;

                n = n / 2;
            }
        }
    }

    return res;


}

string decodeString(string s) {
        int i = 0;
        string res = process(s , i);

        return res;
}

int main(){
    string s = "3[a2[c]]ef";

    cout << decodeString(s);

    return 0;
}
