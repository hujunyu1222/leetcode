#include <iostream>
#include <string>

using namespace std;



int main(){
    string s;

    cin >> s;

    int index[26];

    for (int i = 0; i < 26; i++){
        index[i] = -1;
    }



    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'C' && index[s[i] - 'A'] == -1){
            index[s[i] - 'A'] = i;
        }
        else if (s[i] == 'F'){
            index[s[i] - 'A'] = i;
        }
    }

    if (index[2] == -1 || index[5] == -1 || (index[2] > index[5])){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}
