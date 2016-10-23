#include <iostream>
using namespace std;

bool wordPattern(string pattern, string str) {

    vector<string> tokens;
    istringstream iss(str);
    unordered_map<char, int> p2i;
    unordered_map<string, int> w2i;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

    if (pattern.length() != tokens.size())  {
        return false;
    }


    for (int i = 1; i < pattern.length() + 1; i++) {
        //同时增加，不等即不符合pattern
        p2i[pattern[i - 1]] += i;
        w2i[tokens[i - 1]] += i;
        if (p2i[pattern[i - 1]] != w2i[tokens[i - 1]]) {
            return false;
    }
}

return true;

}

int main(){

    return 0;
}
