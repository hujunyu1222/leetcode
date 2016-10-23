#include <iostream>
#include <string>
#include <stack>

using namespace std;

int maxLen = -1;

int dp(string s){
    int n = s.size();
    stack<char> st;
    int length = 0;
    int index = 0;

    if (s[0] == ')') {
        length = dp(s.substr(1));
        return 0;
    }

    while (index < n){

        if (s[index] == '('){
            st.push('(');
        }
        else if (s[index] == ')'){
            st.pop();
            length += 2;
        }
        if (length > maxLen){
            maxLen = length;
        }
        cout << s <<":"<< length << endl;

        if (st.empty()){
            if (index != s.size() - 1)
            {
                length += dp(s.substr(index+1));
                if (length > maxLen){
                    maxLen = length;
                }
                return length;
            }
            else{
                return length;
            }
        }

        //cout << s << "n" << n << "length" << length << endl;
        index++;

    }
    cout << "out" << s << endl;
    return 0;

}




int main(){
    string s = "(()(((()";
    dp(s);
    cout << maxLen;
    return 0;
}
