#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <memory.h>
#include <vector>


using namespace std;

class Base{
private:
    int val;
public:
    Base(){}
    Base(int x): val(x){}

    virtual void print(){cout << "Base" << endl;}

    int getX(){return val;}

    static void staPrint(){
        cout << "call static Print function" << endl;
    }

};

class Derived : public Base{
private:
    int val;
public:
    void print(){cout << "Derived" << endl;}

};

class DDerived: public Derived{
private:
    int val;
public:
    void print(){cout << "DDerived" << endl;}


};

void update(Derived *p){
    if (p == NULL){
        cout << "pointer is pointed to NULL" << endl;
        return; 
    }
    p->print();
}

void updateViaRef(Derived d){
    d.print();
}

int main(){
    Base *b = new Base;
    Derived * d = new Derived;

    void* rawMemory = operator new[] (10 * sizeof (Base));

    Base *arrB = static_cast<Base*>(rawMemory);

    for (int i = 0; i < 10; i++){
        new (arrB + i) Base(i);
    }

    for (int i = 0; i < 10; i++){
        cout << arrB[i].getX() << endl;
    }  

    vector<int> res;
    res.push_back(1);

    system("pause");

    return 0;
}