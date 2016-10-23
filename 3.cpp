#include <iostream>
using namespace std;

int a[5] = {6,4,3,5,1};

int partition (int p , int q)
{
    int x = a[p], i = p;
    int j;
    for(j = p +1; j <= q; j ++)
        if(a[j] <= x) swap (a[++i], a[j]);
            swap (a[p], a[i]);
    return i;
}

int select ( int p , int r , int k){
	if(p == r) return p;
	int q = partition(p,r);
	int j = q-p+1;
	if(k==j) {return q;}
	else if(k<j) {return select(p,q,k);}
	else {return select(q+1,r,k-j);}

}
int main(){
    int i =0;
    int index = 0;


    //int r = partition(0,4);
    //cout<<r<<endl;
    index = select(0,4,2);
    cout<<a[index]<<endl;



    for(int k =0;k<5;k++)
        cout<<a[k]<<endl;


    return 0;
}
