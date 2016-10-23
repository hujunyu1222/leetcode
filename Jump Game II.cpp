#include <iostream>
#include <vector>
#include <string>


using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int i, j;
    int maxIndex = -1, maxNum = -1;
    int step = 0, index = 0;
    bool flag = false;

    if (n == 1) return 0;

    i = 0;


    while(i < n){
        maxIndex = -1;

        for (j = 1; j <= nums[i]; j++){
            if (i + j >= n - 1) return ++step;

            if (nums[i+j]+i+j > maxIndex){
                maxIndex = nums[i+j]+i+j;
                index = i+j;
            }

        }
        step ++;

        i = index;

    }
    //cout << maxNum;

    return step;

}

int main(){

}


