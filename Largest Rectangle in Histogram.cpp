#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> stk;
    int n = heights.size();
    int i = 0, index;
    int curArea, maxArea;

    maxArea = 0;

    while(i < n)
    {
        if(stk.empty() || heights[stk.top()] <= heights[i]){
            stk.push(i++);
        }
        else{
            index = stk.top();
            stk.pop();
            curArea = heights[index] * (stk.empty() ? i : i - stk.top() - 1);
            maxArea = max(maxArea, curArea);
        }
    }

    while(!stk.empty())
    {
        index = stk.top();
        cout << heights[index] << endl;
        stk.pop();
        int curArea = stk.empty()? n * heights[index]:(n-stk.top()-1)*heights[index];
        maxArea = max(maxArea,curArea);
    }


    return maxArea;
}

int main(){
    int a[6] = {5,2,8,9,1};
    vector<int> v(a, a+5);

    cout << largestRectangleArea(v) << endl;

    return 0;

}
