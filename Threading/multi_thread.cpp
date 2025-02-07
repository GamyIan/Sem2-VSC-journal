#include <iostream>
#include <thread>
#include <future>

using namespace std;

long add(long j,long k,string th)
{
    for(long i=1;i<=j;i++)
    {
        k+=j;
    }
    cout << "Thread " << th << " finished: " << k << endl;
    return k;
}

int main()
{
    future<long> t1=async(add,211239,30,"t1");
    future<long> t2=async(add,221261378,40,"t2");
    future<long> t3=async(add,3212112,70,"t3");

    //cout << "Thread 1: " << t1.get() << endl;
    //cout << "Thread 2: " << t2.get() << endl;
    //cout << "Thread 3: " << t3.get() << endl;

    return 0;
}

// How can you parrarel write and parralell read