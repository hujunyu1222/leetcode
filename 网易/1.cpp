#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, s, L;
    cin >> n >> s >> L;

    if (n <= 0) return 0;

    int oneCD = (L + 1)/(s + 1);
    if (oneCD % 13 == 0){
        oneCD--;
    }



    int sum = n / oneCD;
    int rest = n % oneCD;

    /*
    if (rest != 0){
        sum++;
        if (rest % 13 == 0 ){
            if (sum == 1){
                sum ++;
            }
            else if (rest == oneCD - 1){
                sum ++;
            }
    	}
    }
    */



    if (rest % 13 == 0 && rest != 0){
        if (sum == 0){
            sum += 2;
        }
        else if (rest == oneCD - 1){
            sum += 2;
        }
    }else if (rest != 0){
        sum++;
    }


    cout << sum << endl;




    return 0;

}
