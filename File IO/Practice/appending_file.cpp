#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    fstream file;
    file.open("file.csv", ios::app);

    string fname,lname;
    int age;
    char c=',';

    cout << "Enter First name: ";
    cin >> fname;

    cout << "Enter Last name: ";
    cin >> lname;

    cout << "Enter Age: ";
    cin >> age;

    file << fname << c << lname << c << age << endl;

    file.close();
    return 0;
}