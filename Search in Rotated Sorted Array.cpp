#include <iostream>
#include <vector>

using namespace std;

int SearchRotate(vector<int> nums, int target){

if (nums.size() == 0) return -1;
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] >= nums[l]) {
            if (target <= nums[m] && target >= nums[l]) r = m;
            else l = m + 1;
        } else {
            if (target > nums[m] && target <= nums[r]) l = m + 1;
            else r = m;
        }
    }
    return nums[l] == target ? l : -1;
}

void PrintVec(vector<int> &nums){
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout <<'\n';
}

int main(){
    int a[] = {3, 1};
    vector<int> nums(a,a+2);
    //PrintVec(nums);
    int tmp = -6;
    //cout << tmp << ":" <<tmp * 2 << endl;
    int b = 5;
    cout <<"Multiply: " << b*tmp << endl;
    cout << "bit: " << (b<<1) - (b<<3)<< endl;
    cout << "Change:" << (b << 31) + (b << 31) - (b << 29) << endl;


    return 0;

}


