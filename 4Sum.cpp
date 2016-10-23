#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > res;
    if (nums.size() < 4) return res;

    vector<int> triple(4);


    sort(nums.begin(), nums.end());

    int n = nums.size();
    int i, j ,k, l;
    int prei, prej;

    for (i = 0; i < n-3; i++){
        //去重
        if (i!=0 && (nums[i] > target || nums[i] == prei)) continue;
        //cout << "prei:" << nums[i] << endl;
        prei = nums[i];
        triple[0] = nums[i];
        for (j = i + 1; j < n -2; j++){
            if (j != i+1 && (nums[j] + nums[i] > target || nums[j] == prej)) continue;

            //cout << "prej:" << nums[j] << endl;
            prej = nums[j];
            triple[1] = nums[j];

            k = j + 1;
            l = n - 1;
            while (l > k){
                triple[2] = nums[k];
                triple[3] = nums[l];
                int sum = triple[0] + triple[1] + triple[2] + triple[3];
                if (target  == sum){
                    if (res.size() == 0){
                        res.push_back(triple);
                    }
                    else if (res.back() != triple){ //去重
                        res.push_back(triple);
                    }

                    ++k;
                    --l;
                }
                else if (target < sum){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<vector<int> > res;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    res = fourSum(nums, 0);



    for (vector<vector<int> >:: iterator itr1 = res.begin(); itr1 != res.end(); itr1++){
        for (vector<int>:: iterator itr2 = itr1->begin(); itr2 != itr1->end(); itr2++){
            cout << *itr2 <<',';
        }
        cout << endl;
    }


    return 0;
}
