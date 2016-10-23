#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void heapInsert(vector<int> &nums, int i){
    int parent = 0;
    while(i != 0){
        parent = (i - 1) / 2;
        if (nums[parent] < nums[i]){
            swap(nums[parent], nums[i]);
            i = parent;
        }
        else{
            break;
        }
    }

}

void heapify(vector<int> &nums, int i, int length){
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;

    while(left < length){
        if (nums[left] > nums[i]){
            largest = left;
        }
        if (right < length && nums[right] > nums[largest]){
            largest = right;
        }

        if (largest != i){
            swap(nums[i], nums[largest]);
        }
        else{
            break;
        }
        i = largest;
        left = i * 2 + 1;
        right = i * 2 + 2;

    }

}


int main(){
    int a[] = {10,64,21,41,17,6,12,31,77,36};
    vector<int> nums(a, a + 10);

    int i;

    for (i = 0; i < nums.size(); i++){
        heapInsert(nums, i);
    }

    for (i = nums.size() - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }


    for (auto x:nums){
        cout << x << " ";
    }

    return 0;
}
