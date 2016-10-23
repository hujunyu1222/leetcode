#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();

        int rowl, rowr, rowmid;
        rowl = 0;
        rowr = M - 1;
        rowmid = (rowl + rowr) / 2;
        while(rowl <= rowr){
            if (matrix[rowmid][N-1] == target){
                return true;
            }
            else if (matrix[rowmid][N-1] < target){
                rowl = rowmid + 1;
                rowmid = (rowl + rowr) / 2;
            }
            else{
                rowr = rowmid - 1;
                rowmid = (rowl + rowr) / 2;
            }
        }
        if (rowmid != M - 1 && matrix[rowmid][N-1] < target){
            rowmid++;
        }
        int rowMinIndex = rowmid;

       while(rowl <= rowr){
            if (matrix[rowmid][N-1] == target){
                return true;
            }
            else if (matrix[rowmid][N-1] < target){
                rowl = rowmid + 1;
                rowmid = (rowl + rowr) / 2;
            }
            else{
                rowr = rowmid - 1;
                rowmid = (rowl + rowr) / 2;
            }
        }
        if (rowmid != M - 1 && matrix[rowmid][0] < target){
            rowmid++;
        }

         int rowMaxIndex = rowmid;

        cout << "rowMinIndex" << rowMinIndex <<endl;
        cout << "rowMaxIndex" << rowMaxIndex <<endl;

        int coll, colr, colmid;

        for (int i = rowMinIndex; i <= rowMaxIndex; i++){
            coll = 0; colr = N-1;
            colmid = (coll + colr) / 2;
            while(coll <= colr){
                if (matrix[i][colmid] == target){
                    return true;
                }
                else if (matrix[i][colmid] < target){
                    coll = colmid + 1;
                    colmid = (coll + colr) / 2;
                }
                else{
                    colr = colmid - 1;
                    colmid = (coll + colr) / 2;
                }
            }

        }
        /*
        coll = 0; colr = colIndex;
        colmid = (coll + colr) / 2;

        while (coll <= colr){
            if (matrix[rowIndex][colmid] == target){
                return true;
            }
            else if (matrix[rowIndex][colmid] < target){
                coll = colmid + 1;
                colmid = (coll + colr) / 2;
            }
            else{
                colr = colmid - 1;
                colmid = (coll + colr) / 2;
            }
        }
        */

        return false;
}

int main(){
    vector<vector<int> > m = {{-1,2,3}};
   if (searchMatrix(m, -1)){
        cout << "True" << endl;
   }
   else{
        cout << "False" << endl;
   }


    return 0;
}
