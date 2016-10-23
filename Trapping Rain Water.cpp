#include <iostream>
#include <vector>
#include <string>


using namespace std;

int partWater(int s, int e, vector<int>& height){
    int lower = min(height[s], height[e]);
    int higher = max(height[s], height[e]);
    int sum = 0;

    int i;
    for (i = s + 1; i < e; i++){
        sum += lower - height[i];
    }

    return sum;

}

int trap(vector<int>& height) {
    int i = 0, j, k;
    while(height[i] == 0) i++;

    int n = height.size();
    int sumWater = 0;
    int index = 0;

    j = i + 1;

    while (j < n){
       while (height[j] < height[i])j++;
       if (j >= n) break;
       sumWater +=  partWater(i, j, height);
       i = j;
       j = i + 1;
    }

    cout << "1:" << sumWater << endl;
    index = i;
    i = n - 1;
    j = i - 1;
    cout << "index:" << index << endl;

    while (j >= index){
        while(height[j] < height[i])j--;
        if (j < index) break;
        sumWater +=  partWater(j, i, height);
        i = j;
        j = i - 1;

    }
        cout << "2:" << sumWater << endl;

    return sumWater;


}

int main(){
    int a[] = {6,1,0,2,1,0,1,3,2,1,2,6};
    vector<int> height(a,a+11);

    cout << trap(height);

    return 0;
}
