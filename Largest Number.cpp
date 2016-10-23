#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool compare(int a, int b){
    char s1[1000000];
    char s2[1000000];

    string str1;
    string str2;

    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    str1 = s1;
    str2 = s2;
//   cout<<str1.length()<<"  "<<str2.length()<<endl;
//    if (strcmp(s1,s2)> 0){
    if (str1 + str2 > str2 + str1){
        return true;
    }
    else{
        return false;
    }


}

int main()
{
    int a = 21;
    int b = 212;


    if (compare(a,b)){
        cout<<"a > b";
    }
    else{
        cout<<"a <= b";
    }



    return 0;
}
