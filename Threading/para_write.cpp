// Write parrarell write to two different files odd.txt and even.txt
#include <iostream>
#include <thread>
#include <fstream>
#include <string>

using namespace std;

bool t1=1, t2=1;

void even()
{
    fstream eve;
    eve.open("Files/even.txt",ios::app);
    int n=0;
    cout << "Even writing started" << endl;
    while (t1)
    {
        eve << n << endl;
        n+=2;
    }
    eve.close();
    cout << "Even writing stopped" << endl;
}

void odd()
{
    fstream file;
    file.open("Files/odd.txt",ios::app);
    int n=1;
    cout << "Odd writing started" << endl;
    while (t2)
    {
        file << n << endl;
        n+=2;
    }
    file.close();
    cout << "Odd writing stopped" << endl;
}

void stop()
{
    t1 = 0;
    t2 = 0;
}

int main()
{
    cout << "Stop the threads by pressing n" << endl;
    thread th1(even);
    thread th2(odd);

    string inp;
    getline(cin,inp);
    stop();
    th1.join();
    th2.join();
    return 0;
}