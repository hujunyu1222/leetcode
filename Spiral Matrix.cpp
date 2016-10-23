#include <iostream>
#include <vector>
#include <string>


using namespace std;

//[[ 1, 2, 3 ],[ 4, 5, 6 ],[ 7, 8, 9 ]]

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i, j;

        int x1 = 0;
        int y1 = 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        while (rows >= 1 && cols >= 1){
            int x2 = x1 + rows - 1;
            int y2 = y1 + col - 1;

            for (i = y1; i <= y2; i++){
                res.push_back(matrix[x1][i]);
            }

            for (j = x1 + 1; j < x2; j++){
                res.push_back(matrix[j][y2]);
            }

            if (rows > 1){
                for (i = y2; i >= y1; i--){
                    res.push_back(matrix[x2][i]);
                }
            }

            if (cols > 1){
                for (j = x2 - 1; j > x1; j--){
                    res.push_back(matrix[j][y1]);
                }
            }
            rows -= 2;
            cols -= 2;
            x1++;
            y1++;


        }

        return res;


}
