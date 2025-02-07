#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <map>

using namespace std;

double evalPar(stringstream& ss);
double evalFact(stringstream& ss);
double evalExp(stringstream& ss);
double evalPow(stringstream& ss);
double evalVar(stringstream& ss);

map<string, double> variables; // Holds variables and their values

string removeSpaces(string inp)
{
    string output;
    for (char ch : inp)
    {
        if (ch != ' ') {output+=ch;}
    }
    return output;
}

double evalPar(stringstream& ss) {
    double num;
    if (ss.peek() == '(') 
    {
        ss.get(); 
        num = evalExp(ss);
        ss.get();
    } else {ss >> num;}
    return num;
}

double evalPow(stringstream& ss) {
    double left = evalPar(ss);
    while (true) {
        char op = ss.peek();
        if (op == '^') {
            ss.get();
            double right = evalPow(ss);
            left = pow(left, right);
        } else {break;}
    }
    return left;
}

double evalVar(stringstream& ss) {
    string varName;
    char next = ss.peek();

    if (isalpha(next)) {  // If it starts with a letter, it's a variable
        while (isalnum(ss.peek())) {  // Read full variable name
            varName += ss.get();
        }

        if (ss.peek() == '=') {  // Assignment (x = 5)
            ss.get();  // Consume '='
            double value = evalExp(ss);
            variables[varName] = value;  // Store in map
            return value;
        }

        if (variables.find(varName) != variables.end()) {
            return variables[varName];  // Return stored value
        } else {
            throw runtime_error("Undefined variable: " + varName);
        }
    }

    return evalPow(ss);  // If not a variable, evaluate as normal
}

double evalFact(stringstream& ss) {
    double left = evalVar(ss);
    while (true) {
        char op = ss.peek();
        if (op == '*' || op == '/') {
            ss.get();
            double right = evalVar(ss);
            if (op == '*') {
                left *= right;
            } else {
                left /= right;
            }
        } else {break;}
    }
    return left;
}

double evalExp(stringstream &ss)
{
    double left = evalFact(ss);
    while (true) {
        char op = ss.peek();
        if (op == '+' || op == '-') {
            ss.get();
            double right = evalFact(ss);
            if (op == '+') {
                left += right;
            } else {
                left -= right;
            }
        } else {
            break;
        }
    }
    return left;
}

int main()
{
    cout << "Simple C++ Math Interpreter\nEnter expression or type 'exit'/'q' to quit" << endl;

    string input;
    while (true)
    {
        cout << ">> ";
        getline(cin,input);
        input = removeSpaces(input);
        if (input == "exit" or input == "q") {break;}

        stringstream ss(input);
        try
        {
            double result = evalExp(ss);
            cout << "Result: " << result << endl;
        }
        catch (const exception& e)
        {
            cout << "[ERROR]: "<< e.what() << endl;
        }
    }

    cout << "Stopping Interpreter..." << endl;

    return 0;
}