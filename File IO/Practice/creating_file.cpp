#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    string a = "This file was created on: ";
    time_t t = time(0);
    a.append(ctime(&t));
    a.append("FirstName,Lastname,Age\n");

    fstream file;
    file.open("file.csv", ios::out);

    file << a;

    file.close();
    return 0;
}