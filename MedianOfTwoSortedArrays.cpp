/*
经典：找两个已排序数组的中位数。
变形：找两个已排序数组的第K个大的数
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findk(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int k){
    if (m > n){
        findk(b, n, a, m, k);
    }
    if (m == 0){
        return *(b+k-1);
    }
    if (k == 1){
        return min(*(a+k-1), *(b+k-1));
    }

    int pa = min(k/2, m);
    int pb = k - pa;
    //不断减去a或b的左端（a的pa左端或b的pb右端）
    cout << "k =" << k <<endl;
    cout << *(a+pa-1) << "  " << *(b+pb-1) <<endl;
    if (*(a+pa-1) < *(b+pb-1)){
        return findk(a+pa, m-pa, b, n, k-pa);
    }
    else if (*(a+pa-1) > *(b+pb-1)){
        return findk(a, m, b+pb, n-pb, k-pb);
    }
    else{
        return *(a+pa-1);
    }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int total = n1 + n2;
    if (total % 2 == 0){
        return (findk(nums1.begin(), n1, nums2.begin(), n2, total/2) + findk(nums1.begin(), n1, nums2.begin(), n2, total/2+1))/2.0;
    }
    else{
        return findk(nums1.begin(), n1, nums2.begin(), n2, total/2+1);
    }

}

int main(){
    vector<int> num1 = {2,3,4,5};
    vector<int> num2 = {1};
    double result = findMedianSortedArrays(num1, num2);

    cout << result << endl;
    return 0;
}
