#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

stack<char> leftP;

void backtracking(int l, string s, vector<string> &res){
    cout << l << endl;
    if (leftP.empty()){
        if (l == 0){
            res.push_back(s);
            return;
        }
        else{
           backtracking(l-1, s+')', res);
        }
    }
    else if (l != 0){
        leftP.pop();
        backtracking(l+1, s+'(', res);
        leftP.push('(');


        backtracking(l-1, s+')', res);

    }
    else{
        leftP.pop();
        backtracking(l+1, s+'(', res);
        leftP.push('(');
    }

    return;

}




int main(){
    vector<string> res;
    int n;
    string s = "";
    cin >> n;

    while(n--){
        leftP.push('(');
    }

    backtracking(0, s, res);

    for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++){
        cout << *iter << endl;
    }

    return 0;
}
