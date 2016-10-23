#include <iostream>
using namespace std;


int partition(int a[], int l, int r)
{
    int i;
    int p = l;
    int j;

    int x = a[p];


    for(j=p+1, i=p; j<r+1; j++)
    {
        if(a[j] < x )
        {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i], a[p]);

    return i;
}

void QuickSort(int Array[], int left, int right)
{
    if (right <= left) return;
    int pivot;

    pivot = partition(Array, left, right);
    cout<<pivot<<endl;

    QuickSort(Array, left, pivot-1);
    QuickSort(Array, pivot+1, right);
}

int main(){

    int array[10]={9,3,7,8,0,4,1,2,6,5};
    int i;

    QuickSort(array,0,9);

    cout<<"+++++++++++++++++"<<endl;
    for (i=0;i<10;i++){
        cout<<array[i]<<endl;
    }

    return 0;



}
