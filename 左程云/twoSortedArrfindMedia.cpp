#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//the length of these two arrays are equal.
int findMedia(vector<int> &nums1, vector<int> &nums2){
    int res = 0;
    int start1, end1, start2, end2;
    int mid1, mid2;
    int offset;

    start1 = start2 = 0;
    end1 = end2 = nums1.size() - 1;

    while( start1 < end1){
        mid1 = (start1 + end1) >> 1;
        mid2 = (start2 + end2) >> 1;

        offset = ((end1 - start1 + 1) & 1) ^ 1;

        if (nums1[mid1] == nums2[mid2]){
            return nums1[mid1];
        }
        else if (nums1[mid1] > nums2[mid2]){
            end1 = mid1;
            start2 = mid2 + offset;
        }
        else{
            end2 = mid2;
            start1 = mid1 + offset;
        }

    }

    //when start1 equals end1
    return min(nums1[start1], nums2[start2]);

}

int main(){
    vector<int> nums1{3,5,8,10,13};
    vector<int> nums2{1,4,7,9,15};

    cout << findMedia(nums1, nums2);


    return 0;
}
