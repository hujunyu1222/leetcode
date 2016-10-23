#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

    string simplifyPath(string path) {
     int n = path.size();
    if (n > 1 && path[n - 1] != '/'){
        path += '/';
    }

    stringstream ss(path);
    stack<string> st, res;


    char c;
    string s = "";
    string result = "";

    if (path.size() == 0) return result;

    //cout << path << endl;

    st.push("/");

    while(ss>>c){
        if (c == '/'){
            if (s != "" && s != "." && s != ".."){
                st.push(s);
                st.push("/");
            }
            else if(s == ".."){
                if (st.size() != 1){
                    st.pop();
                    st.pop();
                }

            }
            s = "";
        }
        else{
            s += c;
        }
    }
    if (s != ""){
        st.push(s);
    }
    while ((st.top() == "/" || st.top() == ".") && st.size() != 1) st.pop();

    while (!st.empty()){
        //cout << st.top() << endl;
        res.push(st.top());
        st.pop();
    }
    while (!res.empty()){
        result += res.top();
        res.pop();
    }
    //cout << result << endl;
    return result;
}

int main(){
    string tmp = "/home/";
    cout << simplifyPath(tmp);

    return 0;

}
