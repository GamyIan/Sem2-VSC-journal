#include <iostream>

using namespace std;

class A {
    public:
    void show() {
        cout << "Show from Class A" << endl;
    }
};

class B {
    public:
    void show(){
        cout << "Show from Class B" << endl;
    }
};

class C : public A, public B {
    public:
    void display(){
        //Resolves ambiguity by using the ::
        A::show();
        B::show();
    }
};

int main()
{
    C obj;
    obj.display();
    return 0;
}