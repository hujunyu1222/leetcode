#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include "largest Rectangle in Histogram.cpp"

using namespace std;

#define DEBUG(X) cout<<#X<<X<<endl


 int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)return 0;
        int n = matrix[0].size();
        if(n == 0)return 0;

        vector<int> heights(n,0);
        int maxArea = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                heights[j] = (matrix[i][j] == '0' ? 0 : heights[j]+1);
            }
            maxArea =  max(largestRectangleArea(heights), maxArea);
        }






        return maxArea;

}

int main(){



    matrix[1][2] = matrix[1][3] = matrix[2][1] = matrix[2][2] = matrix[2][3] = '1';
    matrix[3][1] = matrix[3][2] = matrix[3][3] = matrix[3][4] = '1';
    matrix[4][2] = matrix[4][3] = '1';



    int i,j;
    int lng, wid, tmp;
    int maxS = 0x80000000;



    cout << maxS << endl;
    return 0;
}
