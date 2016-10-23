#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(int a[], int l, int r){
    int i,j;
    int p;
    int x;

    p = i = l;
    j = i+1;
    x = a[l];

    for(j=i+1; j<=r; j++){
        if (a[j]<=x){
            swap (a[++i],a[j]);
        }
    }
    swap(a[i],a[p]);

    return i;
}

int quickSelect(int a[], int l, int r, int k){
    if (r==l) return l;
    int p = partition(a,l,r);
    int j = p - l + 1;

    if (k == j) {
        return p;
    }
    else if (k<j){
        return quickSelect(a,l,p-1,k);
    }
    else {
        return quickSelect(a,p+1,r,k-j);
    }
}

 void wiggleSort(vector<int>& nums) {
        int n = nums.size();

    // Find a median.
    int midptr = n / 2;
    nth_element(nums.begin(), nums.begin()+midptr, nums.end());
    int mid = nums[midptr];

    // Index-rewiring.
    //n|1 : 用于处理奇偶数的情况
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;

    }

    }

int main(){
    int a[6]={25,13,33,40,62,10};
    nth_element(a, a+6/2, a+6);

    for (int i=0;i<6;i++)
    cout<<a[i]<<endl;


    return 0;
}
