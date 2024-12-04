#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    bool first = true;
    fstream file;
    file.open("file.csv", ios::in);
    string data,val;


    while (getline(file,data)){
        if(first){
            first = false;
            continue;
        }
        stringstream ss(data);
        while (getline(ss,val,',')){
            cout << setw(15) << val;
        }
        cout << endl;
    }
    return 0;
}