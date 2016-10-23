#include <iostream>
#include <bits/stdc++.h>


using namespace std;


//线程安全队列
//window下无法编译通过，而linux可以


template<typename Data>
class concurrent_queue
{
private:
    queue<Data> the_queue;
    mutex the_mutex;
    condition_variable the_condition_variable;
public:
    void push(Data const& data)
    {
        mutex::scoped_lock lock(the_mutex);
        the_queue.push(data);
        lock.unlock();
        the_condition_variable.notify_one();
    }

    bool empty() const
    {
        mutex::scoped_lock lock(the_mutex);
        return the_queue.empty();
    }

    bool try_pop(Data& popped_value)
    {
        mutex::scoped_lock lock(the_mutex);
        if(the_queue.empty())
        {
            return false;
        }

        popped_value=the_queue.front();
        the_queue.pop();
        return true;
    }

    void wait_and_pop(Data& popped_value)
    {
        mutex::scoped_lock lock(the_mutex);
        while(the_queue.empty())
        {
            the_condition_variable.wait(lock);
        }

        popped_value=the_queue.front();
        the_queue.pop();
    }

};




int main(){
    concurrent_queue<int> A;

    return 0;
}
