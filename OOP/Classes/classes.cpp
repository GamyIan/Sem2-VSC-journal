#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name,email;
        int uid;
    
    void displayInfo(){
        cout << "Student Info:" << endl;
        cout << "UID: " << uid << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

int main()
{
    Student Student1;

    cout << "Enter student UID: ";
    cin >> Student1.uid;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin,Student1.name);

    cout << "Enter student Email: ";
    getline(cin,Student1.email);

    Student1.displayInfo();

    return 0;
}