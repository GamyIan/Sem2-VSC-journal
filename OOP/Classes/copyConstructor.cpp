#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        string name,email;
        int uid;
    
    Student(int id, string nm, string mail) : uid(id), name(nm), email(mail) {}

/*
    Student(const Student &p){                      Not needed cuz it works anyways
        uid = p.uid;                            
        name = p.name;
        email = p.email;
    }
*/
    
    void displayInfo(){
        cout << "Student Info:" << endl;
        cout << "UID: " << uid << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

int main()
{
    string name,email;
    int uid;

    cout << "Enter student name: ";
    getline(cin,name);

    cout << "Enter student Email: ";
    getline(cin,email);

    cout << "Enter student UID: ";
    cin >> uid;

    Student stu(uid,name,email);
    Student stuwart=stu;
    stuwart.displayInfo();

    return 0;
}