#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



//转化为2Sum问题
//K-Sum可以转换为(K-1)-Sum
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    if (nums.size() < 3) return res;

    vector<int> triple(3);
    int target = 0;


    sort(nums.begin(), nums.end());

    int n = nums.size();
    int i, j ,k;
    int pre;

    for (i = 0; i < n-2; i++){
        //去重
        if (i!=0  &&  nums[i] == pre) continue;

        pre = nums[i];
        triple[0] = nums[i];
        j = i + 1;
        k = n -1;
        while (k > j){
            triple[1] = nums[j];
            triple[2] = nums[k];
            int sum = triple[1] + triple[2];
            if (target - triple[0] == sum){
                if (res.size() == 0){
                    res.push_back(triple);
                }
                else if (res.back() != triple){ //去重
                    res.push_back(triple);
                }

                ++j;
                --k;
            }
            else if (target - triple[0] < sum){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return res;
}


int main(){
    vector<vector<int> > res;
    vector<int> nums = {-3, -3, -3, 6};
    res = threeSum(nums);



    for (vector<vector<int> >:: iterator itr1 = res.begin(); itr1 != res.end(); itr1++){
        for (vector<int>:: iterator itr2 = itr1->begin(); itr2 != itr1->end(); itr2++){
            cout << *itr2 <<',';
        }
        cout << endl;
    }


    return 0;
}
