#include <iostream>
#include <string>

using namespace std;

bool isNum(char c){
    int tmp = c - '0';
    if (0 <= tmp && tmp <= 9){
        return true;
    }
    else{
        return false;
    }
}

bool dealE(string s, bool flag){
    int length = s.size();
    int i = 0;

    if (s[i] == '+' || s[i] == '-') i++;
    if (i == length) return false;

    if (s[i] == ' ') return false;

    if (!flag) return false;

    while(isNum(s[i])) i++;

    if (i == length) return true;
    else if (s[i] == ' '){
        while(i < length && s[i] == ' ') i++;
        if (i != length) return false;
        else return true;
    }
    else{
        return false;
    }

}


bool dealDot(string s, bool flag){
    int length = s.size();
    int i = 0;


    if (!flag && s[i] == ' ') return false;

    while(isNum(s[i])) {
        i++;
        flag = true;
    }
    if (i == length) return true;
    else if (s[i] == 'e'){
        if (i == length - 1) return false;
        else return dealE(s.substr(i+1), flag);
    }
    else if (s[i] == ' '){
        while(i < length && s[i] == ' ') i++;
        if (i != length) return false;
        else return true;
    }
    else{
        return false;
    }

}



bool isNumber(string s) {
    int length = s.size();
    int i = 0;
    bool flag = true;

    //È¥³ýÇ°¶Ë¿Õ¸ñ
    while(i < length && s[i] == ' ') i++;
    if (i == length) return false;

    if (s[i] == '+' || s[i] == '-') i++;

    if (s[i] == '.'){
        if (i == length - 1) return false;
        else {
            flag = false;
            return dealDot(s.substr(i+1),flag);
        }
    }
    else if (!isNum(s[i])) return false;


    while (isNum(s[i])) i++;
    if (i == length) return true;

    if (s[i] == '.'){
        flag = true;
        if (i == length - 1) return true;
        else return dealDot(s.substr(i+1),flag);
    }
    else if (s[i] == 'e'){
        if (i == length - 1) return false;
        else return dealE(s.substr(i+1),flag);
    }
    else if(s[i] == ' '){
        while(i < length && s[i] == ' ') i++;
        if (i != length) return false;
        else{
            return true;
        }
    }
    else{
        return false;
    }


}

int main(){
    string s;
    cin >> s;

    if (isNumber(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
