#include <iostream>
#include <vector>

using namespace std;

int findtheDupNum(const vector<int> &v){
    int n = v.size();
    int p1, p2;
    int pre;

    p1 = p2 = 0;
    pre = 0;


    do{
        p1 = v[p1];
        p2 = v[v[p2]];

    }while(v[p1] != v[p2]);

    p2 = 0;

    while (v[p1] != v[p2]){
        pre= p2;
        p2 = v[p2];
        p1 = v[p1];
        //cout << v[p1] << " " << v[p2] << endl;
    }

    if (p1 == p2){
        return v[pre];
    }
    else{
        return v[p1];
    }

}

int main(){
    vector<int> num={1,4,3,1,2};
    cout << findtheDupNum(num);

    return 0;
}
