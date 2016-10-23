#include <iostream>
#include <cstdio>
using namespace std;

void Permutation(char a[], int n){
    if (n == 4){
        printf("%s\n", a);
    }
    else{
        for (int i = n; a[i] != '\0'; i++){
            char temp = a[i];
            a[i] = a[n];
            a[n] = temp;

            Permutation(a, n+1);

            temp = a[i];
            a[i] = a[n];
            a[n] = temp;


        }
    }
}

int main(){
    char c[5] = "abcd";
    Permutation(c,0);

    return 0;
}
