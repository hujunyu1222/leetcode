#include <iostream>
#include <stack>

using namespace std;

/*
仅用递归和栈操作实现一个栈的反转
*/
int getAndRemoveLast(stack<int> &s){
    if (s.empty()) {
        cout << "stack is empty!\n";
        return -1;
    }
    int result = s.top();
    s.pop();
    if (s.empty()){
        return result;
    }
    else{
        int last = getAndRemoveLast(s);
        s.push(result);
        return last;
    }
}

void reverseStack(stack<int> &s){
    if (s.empty()){
        return;
    }
    int i = getAndRemoveLast(s);
    reverseStack(s);
    s.push(i);
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
    s.push(1);s.push(2);s.push(3);
    //Print(s);
    reverseStack(s);
    Print(s);

    return 0;
}
