#include <iostream>
//#include <windows.h>

using namespace std;

void convertUnexpected(){
    cerr << "Catch an Unexpected exception" << endl;
    throw;
}

void f(int val)throw(bad_exception){
    char d = 'a';
    try{
        if (val > 10){
            cout << "do sth" << endl;
        }
        else{
            throw d;
        }

    }
    catch(const int &e){
        cerr << "error: " << e << endl;
        //throw;
    }


}

int maxNum(int &a, int b){
    int c = 10;

    return a + b;


}

int maxNum(int a, int b){
    return a > b ? a : b;

}


int main(){

    set_unexpected(convertUnexpected);

    try{
        f(9);
    }
    /*
    catch(int &a){
        cout << "catch int" << endl;
    }
    */
    catch(exception &e){
        cout << "all the unexpected exceptions can be caught here!" << endl;
    }


    cout << "normal" << endl;

    int a = 5;
    int b = a;

    //cout << maxNum(a,b) << endl;


    return 0;
}
