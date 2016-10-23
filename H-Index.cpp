#include <iostream>
#include <algorithm>
using namespace std;

static bool compare(int a, int b){
    return (a > b);
}

int h_index(int a[], int n){
    int i;
    int index = 0;
    for (i=n-1; i>=0; i--){
        if(a[i] >= index && a[i]!=0){
            index ++;
        }
        else{
            break;
        }
    }
    return index;
}

int main(){
    int a[5]={3,0,6,1,5};
    int index = 0;
    sort(a,a+5);

    for (int i=0;i<5;i++)
        cout<<a[i]<<endl;

    index = h_index(a,5);
    cout<<index<<endl;


    return 0;
}
