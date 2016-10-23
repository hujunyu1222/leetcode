#include <iostream>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;

#define LEFT 1
#define MID 2
#define RIGHT 3
#define INT_MAX 0x7FFFFFFF

int process(int n, int from, int to);

//递归实现的汉诺塔
int hanoiProblem1(int n, int from, int to){
    if (n == 0) return 0;
    else return process(n, from, to);
}

int process(int n, int from, int to){
    if (n == 1) {
        if (from == MID || to == MID){
            printf("move %d from %d to %d\n", n, from, to);
            return 1;
        }
        else{
            printf("move %d from %d to 2\n", n, from);
            printf("move %d from 2 to %d\n", n, to);
            return 2;
        }
    }
    //从中间向两边移动，
    else if (from == MID || to == MID){
        int idle = (from == MID || to == MID)? RIGHT : LEFT;
        int step1 = process(n - 1, from, idle);
        int step2 = 1;
        printf("move %d from %d to %d", n, from, to);
        int step3 = process(n - 1, idle, to);

        return step1 + step2 + step3;
    }
    else{
        int step1 = process(n - 1, from, to);
        int step2 = 1;
        printf("move %d from %d to 2\n", n, from);
        int step3 = process(n - 1, to, from);
        int step4 = 1;
        printf("move %d from 2 to %d\n", n, to);
        int step5 = process(n - 1, from, to);
        return step1 + step2 + step3 + step4 + step5;
    }

}




//非递归汉诺塔
enum Action{
    No, LtoM, MtoL, MtoR, RtoM
};

int fStackTotStack(Action &record, Action preAct, Action nowAct,
                   stack<int> &fStack, stack<int> &tStack, string from, string to){
    if (record != preAct && fStack.top() < tStack.top()){
        tStack.push(fStack.top());
        fStack.pop();
        cout <<"move " << tStack.top() << " from " << from << " to " << to << endl;

        record = nowAct;
        return 1;
    }
    else {
        return 0;
    }

}

int hanoiProblem2(int n){
    stack<int> ls;
    stack<int> ms;
    stack<int> rs;
    ls.push(INT_MAX);
    ms.push(INT_MAX);
    rs.push(INT_MAX);
    Action record = No;

    for (int i = n; i > 0; i--){
        ls.push(i);
    }

    int step = 0;
    string l = "left";
    string m = "middle";
    string r = "right";
    while(rs.size() < n+1){
        step += fStackTotStack(record, MtoL, LtoM, ls, ms, l, m);
        step += fStackTotStack(record, LtoM, MtoL, ms, ls, m, l);
        step += fStackTotStack(record, MtoR, RtoM, rs, ms, r, m);
        step += fStackTotStack(record, RtoM, MtoR, ms, rs, m, r);
    }
    return step;


}



int main(){
    int n;
    cin >> n;
    //int totalStep = hanoiProblem1(n, 1, 3);
    //printf("It will move %d steps\n", totalStep);
    hanoiProblem2(n);
    return 0;
}
