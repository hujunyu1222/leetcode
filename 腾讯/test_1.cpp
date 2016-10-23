#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void f(int a, int b, int c){
    return ;
}

int sum(int a, int b, int c){
    cout << a << b << c << endl;

    return a + b + c;

}

struct client
{ int a; };

struct proxy {
    client *target;
    client *operator->() const
        { return target; }
};

struct proxy2 {
    proxy *target;
    proxy &operator->() const
        { return * target; }
};

void f() {
    client x = { 3 };
    proxy y = { & x };
    proxy2 z = { & y };

    std::cout << x.a << y->a << z->a; // print "333"
}


int main(){

    //f(printf("a"),printf("b"), printf("c"));

    //int i = 1;
    //printf("%d,%d,%d",i++,i,++i);

    f();

    //cout << sum(i++, i, ++i);





    return 0;
}
