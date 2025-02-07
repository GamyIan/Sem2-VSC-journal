#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print(){}; //Stub method or else it breaks


template <typename T>
T add(vector <T> vec){
    T sum = accumulate(vec.begin(), vec.end(), 0.0f);
    return sum;
}

template <typename T,typename... T2>
void print(T var1,T2... var2)
{
    cout << var1 << endl;
    print(var2...);
}

int main(){
    int r1;
    double r2;

    r1=add<int>({2,3});
    r2=add<double>({2.2,3.3,4.4});
    print(r1,r2);
    return 0;
}