#include <iostream>
#include <stdlib.h>
#include <cstdio>


using namespace std;

class Base{
private:
    int val;
public:
    virtual void print(){cout << "Base" << endl;}

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

    void (Base::*p)();

    p = &Base::print;

    Base::staPrint();

    (b->*p)();

    

    try{
        updateViaRef(dynamic_cast<Derived&> (*b) );
    }
    catch(exception e){
        cout << "There is an exception!" << endl;
        system("pause");
    }

    system("pause");

    return 0;
}