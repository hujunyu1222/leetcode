#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int start = 0;
    int i;
    for (i = 0; i < s.size(); i++){
        if (s[i] == ','){
            cout << s.substr(start, i - start) << endl;
            start = i + 1;
        }
    }
    if (s[s.size()-1] != ',') cout << s.substr(start, i - start) << endl;

    return 0;

}

