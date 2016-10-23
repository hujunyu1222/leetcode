#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string change(string s){
        int gap = 'A' - 'a';
        for (int i  = 0; i < s.length(); i++){
            if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25){
                s[i] = s[i] + gap;
            }
            else{
                s[i] = s[i] - gap;
            }
        }
        return s;
}

string trans(string s, int n) {
        string res = "";

        stringstream ss(s);
        string tmp;
        stack<string> rev;
        stack<char> sp;
        int i = 0;
        while(i < n){
            if (s[i] != ' '){
                sp.push('a');
                i++;
                while(s[i]!=' ' && i < n) i++;
            }
            else {
                sp.push(' ');
                i++;
            }

        }

        while(ss>>tmp){
            cout << tmp << endl;
            tmp = change(tmp);
            rev.push(tmp);

        }
        /*
        while(!sp.empty()){
            cout <<sp.top() << endl;
            sp.pop();
        }
        */



        while(!rev.empty() || !sp.empty()){
                cout << res << endl;
            if (!sp.empty() && sp.top() == ' '){
                    cout << "1" << endl;
                while(!sp.empty() && sp.top() != 'a'){
                    res += sp.top();
                    sp.pop();
                }
            }
            else if (!rev.empty()){
                cout << "2" << endl;
                res += rev.top();
                rev.pop();
                sp.pop();
            }
            else{
                cout << "3" << endl;
                res += sp.top();
                sp.pop();
            }
        }
        cout << "ss" << endl;
        return res;
}


int main(){
    string s = "  i Hrllo    ";
    string res = "  ";

    res = trans(s,s.size());
    cout << res << endl;
    return 0;
}
