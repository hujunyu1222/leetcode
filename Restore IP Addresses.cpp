#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long change(string s){
    long long num = 0;
    if (s.size() > 1 && s[0] == '0') return 256;
    for (int i = 0; i < s.size(); i++){
        num = num * 10 + (s[i] - '0');
    }

    return num;
}

bool backtracking(int start, int length, int pos, string &s, string &tmp, vector<string> &res){
    long long addr;
    if (start >= s.size() || length > 3) return false;

    if (pos == 4){
            cout << "in: ";
        addr = change(s.substr(start));
            cout << addr << endl;
        if (addr <= 255){
            tmp += s.substr(start);
            res.push_back(tmp);
            tmp = tmp.substr(0,start);
            return true;
        }
        else{
            return false;
        }
    }
    else{
        while (length <= 3){
           addr = change(s.substr(start,length));
           if (addr <= 255){
             string tmpStr = tmp;
             tmp += s.substr(start,length);
             tmp += '.';
             backtracking(start+length, 1, pos + 1, s, tmp, res);
             tmp = tmpStr;

           }
           else{
             return false;
           }
           length = length + 1;
        }

    }

}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string tmp = "";
    backtracking(0, 1, 1, s, tmp,result);
    return result;
}

template<class T>
void PrintVec(vector<T> &res){
    int n = res.size();
    for (int i = 0; i < n; i++){
        cout << res[i] << endl;
    }
}

int main(){
    string s = "2736786374048";
    vector<string> res;
    res = restoreIpAddresses(s);
    PrintVec(res);
    return 0;
}
