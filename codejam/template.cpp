#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;





void Print(vector<vector<char>> &mp){
    cout << "=================="<<endl;
    for (int i = 0; i < mp.size(); i++){
        for (int j = 0; j < mp[0].size(); j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
    cout << "=================="<<endl;

}

int main(){

    int caseNum = 1;



    freopen("A-large-practice.in", "r", stdin);
    freopen("2010_1A_large_out.txt", "w", stdout);

    printf("Case #%d: ", caseNum++);



    return 0;
}
