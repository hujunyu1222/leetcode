#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Rational{
private:
    int numer;
    int denomi;

public:
    Rational(int x = 0, int y = 1): numer(x), denomi(y){}

    operator double()const{return numer*1.0 / denomi;}

};

class Name{
private:
    string n;
public:
    Name(const string &s): n(s){}

    void print(){
        cout << n << endl;
    }


};

class Array{
public:
    class ArraySize{
    public:
        ArraySize(int num):theSize(num){}
        int getSize(){return theSize;}
    private:
        int theSize;

    };

    Array(ArraySize aS){
        aSize = aS.getSize();
    }

private:
    int aSize;

};

class A{
public:
    int a;
};

class B: public A{
public:
    int b;

    void get(){cout << b << endl;}

};

size_t countChar(const string &str, char ch){
    int cnt = 0;

    for (int i = 0; i < str.size(); ++i){
        if (str[i] == ch){
            ++cnt;
        }
    }

    return cnt;

}

void uppercasify(string &str){

    cout << "Upper : " << str << endl;

}


int main(){
//    void *p = malloc(sizeof(8));
//    new (p) B();
//
//    static_cast<B*>(p)->get();

    char buffer[] = "dont stop the music";
    char ch = 't';

    cout << countChar(buffer, ch) << endl;

    uppercasify(buffer);
    cout << buffer << endl;



    return 0;
}
