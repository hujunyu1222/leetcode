#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getNext(string P){
    int k = -1;
    int i = 0;
    int n = P.size();
    vector<int> next(n);
    next[0] = -1;

    while (i < n){
        while (k >= 0 && P[i] != P[k])
            k = next[k];

        i++;
        k++;
        if (i == n){
            break;
        }
        if (P[i] == P[k]){
            //next特征向量的优化
            next[i] = next[k];
        }
        else{
            next[i] = k;
        }
    }

    return next;

}

int strStr(string haystack, string needle) {
    int lhay = haystack.size();
    int lneed = needle.size();
    vector<int> next(lneed);
    int i, j;


    next = getNext(needle);
    i = j = 0;
    while(i < lhay){

        while (i < lhay && haystack[i] == needle[j]){
            i++;
            j++;
        }
        if (j == lneed){

            return i - lneed;
        }
        else{
            j = next[j];
            if (j == -1){
                i++;
                j = 0;
            }
        }

    }
    return -1;


}



int main(){
    string hay = "mississippi";
    string s = "issip";
    vector<int> v = getNext(s);

    for (auto x:v){
        cout << x << endl;
    }

    cout << strStr(hay, s);

    return 0;

}
