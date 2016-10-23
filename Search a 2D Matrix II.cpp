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
        rowmid++;


        int coll, colr, colmid;
        coll = 0;
        colr = N - 1;
        colmid = (coll + colr) / 2;

        while (coll <= colr){
            if (matrix[rowmid][colmid] == target){
                return true;
            }
            else if (matrix[rowmid][colmid] < target){
                coll = colmid + 1;
                colmid = (coll + colr) / 2;
            }
            else{
                colr = colmid - 1;
                colmid = (coll + colr) / 2;
            }
        }
        cout << "rowmid" << rowmid <<endl;
        cout << "colmid" << colmid <<endl;

        int rowIndex = rowmid;
        int colIndex = colmid;

        rowl = rowIndex; rowr = M - 1;
        rowmid = (rowl + rowr) / 2;

        while (rowl <= rowr){
            if (matrix[rowmid][colIndex] == target){
                return true;
            }
            else if (matrix[rowmid][colIndex] < target){
                rowl = rowmid + 1;
                rowmid = (rowl + rowr) / 2;
            }
            else{
                rowr = rowmid - 1;
                rowmid = (rowl + rowr) / 2;
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
    vector<vector<int> > m = {{1,3,5,7,9},
  {2,4,6,8,10},
  {11,13,15,17,19},
  {12,14,16,18,20}};
   if (searchMatrix(m, 13)){
        cout << "True" << endl;
   }
   else{
        cout << "False" << endl;
   }


    return 0;
}
