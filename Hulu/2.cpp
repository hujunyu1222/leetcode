#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool compare1(const string &s1, const string &s2){
    return s1 < s2;

}


bool compare2(const vector<string> &s1, const vector<string> &s2){
    return s1[0] < s2[0];

}

void subSet(vector<string> single, vector<string> &paras, int cnt, int e, vector<vector<string> > &res){



}

vector<string> allPara(vector<string> &paras){
    vector<string> res;
    string s;

    if (paras[paras.size() - 1] == "S"){
        sort(paras.begin() + 1, paras.end()-1);
        for (int i = 1; i < para.size() - 1; i++){
            res.push_back(paras[i]);
        }
    }
    else{
        sort(paras.begin() + 1, paras.end()-1);
        for (j = 1; j <= paras.size() - 2; j++){
            int k = j;

        }

    }

}

int main(){
    vector<string> N;
    vector<string> UN;

    vector<vector<string> > pN;
    vector<vector<string> > pUN;

    freopen("2.txt", "r", stdin);

    string para;
    string line;
    int a, b, c;
    int n;

    getline(cin, line);


    while(getline(cin, line)){
        cout << line << endl;
        stringstream sline(line);
        sline >> para >> a >> b >> c;

        //cout << para << a << b << c  << endl;

        string s;
        getline(cin , s);
        vector<string> tmp;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == ','){
                s[i] = ' ';
            }
        }
        stringstream ss(s);
        string eachPara;

        if (a == 1){
           N.push_back(para);
        }
        else{
           UN.push_back(para);
        }

        tmp.push_back(para);
        if (c == 1){
            while(ss >> eachPara){
                tmp.push_back(eachPara);
                eachPara = "-" + eachPara;
                tmp.push_back(eachPara);
            }
        }
        else{
            while(ss >> eachPara){
                tmp.push_back(eachPara);
            }
        }

        if (b == 1){
            tmp.push_back("M");
        }
        else{
            tmp.push_back("S");
        }

        if (a == 1){
            pN.push_back(tmp);
        }
        else{
            pUN.push_back(tmp);
        }


    }

    sort(N.begin(), N.end());
    sort(UN.begin(), UN.end());
    sort(pN.begin(), pN.end());
    sort(pUN.begin(), pUN.end());

    /*
    for (auto x : N){
        cout << x << endl;
    }

    for (auto a1 : pUN){
        for (auto a2 : a1){
            cout << a2 << " ";
        }
        cout << endl;
    }
    */




    return 0;
}
