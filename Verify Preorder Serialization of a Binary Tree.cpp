#include <iostream>
#include <stack>

using namespace std;

bool isValidSerialization(string preorder) {
        stack<int> s;
        int i, start;
        string s1 = "";
        int tmp;
        for (start = 0, i = 0; i < preorder.size(); ){
            while(i < preorder.size() && preorder[i] != ',') i++;
            s1 = preorder.substr(start, i - start);
            //cout << s1 << endl;
            start = ++i;
            if (s1 != "#"){
                s.push(2);
            }
            else{
                if (s.empty()) return false;
                cout << s.top() << "|";
                s.top()--;
                cout << s.top() << endl;
                while (!s.empty() && s.top() == 0) {
                    s.pop();
                    if (!s.empty())
                    s.top()--;
                }
            }

        }
        /*
        if (s.top() == 0) s.pop();
        cout << "in\n";
        while(!s.empty()){
            cout << s.top() << ":";
            s.pop();
        }
        */

        return s.empty();
}

int main(){
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";

    if ( isValidSerialization(s) ) cout << "True\n";
    else cout << "False\n";

    return 0;
}
