#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {

        int buck[3]={0};
        int i,j,k;

        for (i=0; i<nums.size(); i++)
        {
            buck[nums[i]] += 1;
        }

        k = 0;
        for (j=0; j<3; j++)
        {
            for (; buck[j]>0; k++)
            {
                nums[k]=j;
                buck[j]--;
            }
        }

}

int partition(vector<int> &num, int s, int e){
    int pivot = num[s];
    int i, j;

    i = j = s;

    while(j <= e){
        if (num[j] < pivot){
            swap(num[++i], num[j++]);
        }
        else{
            j++;
        }
    }

    swap(num[s], num[i]);

    return i;

}

void quickSort(vector<int> &nums, int s, int e){
    if (s >= e) return;

    int n = nums.size();

    int pivot = partition(nums, s, e);
    quickSort(nums, s, pivot - 1);
    quickSort(nums, pivot+1, e);

    return;

}


int main(){
    vector<int> nums{2,11,45,6,84,13,74,36};

    quickSort(nums, 0, nums.size() - 1);

    for (auto x : nums){
        cout << x << " ";
    }
    cout << endl;



    return 0;
}
