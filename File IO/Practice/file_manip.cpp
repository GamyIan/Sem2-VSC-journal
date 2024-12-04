#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
//#include <cctype>
#include <algorithm>

using namespace std;

void create(string filename)
{
    fstream file;
    file.open(filename, ios::out);
    if (file) {cout << "File created sucessfully" << endl;}
    else {cout << "There was an error creating the file." << endl;}
    file.close();
}

void menu()
{
    cout << "Enter what you want to do\n";
    cout << "c - Create a file\n";
    cout << "r - Read a file\n";
    cout << "a - Append to a file\n";
    cout << "q - Exit the program" << endl;
    cout << "Enter Input: ";
}

int main()
{
    string fname;
    menu();
    getline(cin >> ws, fname);
    transform(fname.begin(), fname.end(), fname.begin(),
                  [](unsigned char c) { return std::tolower(c); });  //To convert name to lowercase
    system("clear");

    

    return 0;
}