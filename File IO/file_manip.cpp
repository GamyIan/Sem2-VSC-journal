#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// Makes sure filename ends with .csv
string csv_check(const string& filename) {
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".csv") {
        return filename;
    }
    return filename + ".csv";
}


void create(string filename) {
    int cols;
    string col_name;
    time_t t = time(0);
    filename = csv_check(filename);
    fstream file;
    file.open(filename, ios::out);
    if (file) {
        cout << filename << " file created successfully. " << endl;
    } else {
        cout << "There was an error creating the CSV file." << endl;
    }
    
    //file << "This file was created on: " << ctime(&t);

    cout << "Enter number of columns: ";
    cin >> cols;
    for (int i=0;i<cols;i++){
        cout << "Enter name of column " << i+1 << ": ";
        getline(cin >> ws, col_name);
        file << col_name;
        if (i != cols - 1){file << ",";} // To prevent the last comma
    }
    file << endl;

    file.close();
}


void read(string filename) {
    //bool time=true;
    bool col_names=true;
    string data,val;
    
    filename = csv_check(filename);
    fstream file;
    file.open(filename, ios::in);
    if (file) {
        string line;
        cout << "Contents of " << filename << ": " << endl;
        while (getline(file,data)){
        stringstream ss(data);
        while (getline(ss,val,',')){
            cout << setw(15) << val;
        }
        cout << endl;
    }
    } else {
        cout << "File " << filename << "not found or error opening the file: " << endl;
    }
    file.close();
}


void append(string filename) {
    int col_count=0;
    vector<string> col_names;
    string header;
    filename = csv_check(filename);
    fstream file;
    file.open(filename, ios::app);

    //Checks and calculating number of columns
    if (file) {
        if(getline(file, header)){ // Gets first line and checks if its empty or not
            stringstream ss(header);
            string col_name;

            while (getline(ss, col_name, ',')) { //Gets each value seperated by ,
                col_names.push_back(col_name);  // Appends to the vector
                col_count++;
            }
        }
        else {cout << "File is empty or in improper format" << endl;}
    }
    else {cout << "File " << filename << "not found or error opening the file: " << endl;}
    file.close();


    file.open(filename, ios::app);
    if (file) {
        vector<string> row_data(col_count);
        cout << "The file has " << col_count << " columns. Please provide data for each column:\n";

        // Ask for input for each column
        for (int i = 0; i < col_count; ++i) {
            cout << "Enter value for column '" << col_names[i] << "': ";
            getline(cin >> ws, row_data[i]);
        }

        // Write the new row to the file
        for (int i = 0; i < col_count; ++i) {
            file << row_data[i];
            if (i != col_count - 1) {
                file << ",";
            }
        }
        file << endl;

        cout << "Data appended successfully to " << filename << endl;
    } else {
        cout << "Error opening the file for appending." << endl;
    }
    file.close();
}

// Function to display the menu
void menu() {
    cout << "Enter what you want to do:\n";
    cout << "c - Create a CSV file\n";
    cout << "r - Read a CSV file\n";
    cout << "a - Append to a CSV file\n";
    cout << "q - Exit the program" << endl;
    cout << "Enter Input: ";
}

int main() {
    char input;    
    string fname;

    do {
        menu();
        cin >> input;
        input = tolower(input);
        cin.ignore();            // Clear the input buffer otherwise extra enter gets pressed
        system("clear");

        switch (input) {
            case 'c':
                cout << "Enter filename to create: ";
                getline(cin, fname);
                create(fname);
                break;
            case 'r':
                cout << "Enter filename to read: ";
                getline(cin, fname);
                read(fname);
                break;
            case 'a':
                cout << "Enter filename to append: ";
                getline(cin, fname);
                append(fname);
                break;
            case 'q':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (input != 'q');

    return 0;
}
