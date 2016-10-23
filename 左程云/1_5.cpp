#include <iostream>
#include <stack>

using namespace std;

//利用一个辅助栈，实现另一个栈的排序

void sortStack(stack<int> &stackData){
    stack<int> help;
    int cur;
    while(!stackData.empty()){
        cur = stackData.top();
        stackData.pop();
        while(!help.empty() && cur > help.top()){
            stackData.push(help.top());
            help.pop();
        }

        help.push(cur);
    }
    while(!help.empty()){
        stackData.push(help.top());
        help.pop();
    }
}

void Print(stack<int> &s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    cout <<"===========\n";
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);
    sortStack(s);
    Print(s);
    return 0;
}
