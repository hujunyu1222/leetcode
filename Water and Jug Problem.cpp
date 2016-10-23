#include <iostream>
#include <set>

using namespace std;

bool canMeasureWater(int x, int y, int z) {
    if (z > x + y) return false;
    if (z == x || z == y || z == x + y) return true;
    if (x == 0){
        return y == z ? true : false;
    }

    int tmp = 0;
    int rest = 0;
    while(1){
        while(tmp <= y){
            if (tmp == z) return true;
            tmp += x;

        }
        if (tmp == z) return true;
        tmp = tmp - y;
        if (tmp == x) break;
    }

    return false;
}

//解法二：利用最大公约数
int gcd (int a, int b){
    if (a == 0) return b;
    else return gcd(b%a, a);
}

bool canMeasureWater2(int x, int y, int z) {
    if (z > x + y) return false;
    if (z == x || z == y || z == x+y) return true;
    if (x == 0){
        return y == z ? true : false;
    }

    int num = gcd(x, y);
    return !(z % num);

}



int main(){
    int x, y, z;
    cin >> x >> y >> z;
    if (canMeasureWater2(x,y,z))cout << "Yes\n";
    else cout << "No\n";


    return 0;
}
