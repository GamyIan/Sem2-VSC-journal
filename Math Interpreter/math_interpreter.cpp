#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

string removeSpaces(string inp);
double evalPar(stringstream& ss);
double evalExp(stringstream& ss);
double evalFact(stringstream& ss);
double evalPow(stringstream& ss);
double evalVar(stringstream& ss);
double evalFunc(stringstream& ss);
vector<double> parseArgs(stringstream& ss);

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
    double left = evalFunc(ss);  // Call evalFunc() first to check for function calls
    while (true) {
        char op = ss.peek();
        if (op == '^') {
            ss.get();
            double right = evalFunc(ss);
            left = pow(left, right);
        } else {
            break;
        }
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
            cout << "[ERROR]: Undefined variable: " << varName << endl;
            return 0;  // Return 0 instead of throwing an error
        }
    }

    return evalPar(ss);  // If not a variable, evaluate as normal
}


double evalFact(stringstream& ss) {
    double left = evalPow(ss);
    while (true) {
        char op = ss.peek();
        if (op == '*' || op == '/') {
            ss.get();
            double right = evalPow(ss);
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

double evalFunc(stringstream& ss) {
    string funcName;
    char next = ss.peek();

    if (isalpha(next)) {  // Function name starts with a letter
        while (isalnum(ss.peek())) {  // Read function name
            funcName += ss.get();
        }

        if (ss.peek() == '(') {  // Function call detected
            ss.get();  // Consume '('
            vector<double> args = parseArgs(ss);
            ss.get();  // Consume ')'

            // Function behavior
            if (funcName == "add") {
                return args[0] + args[1];
            } else if (funcName == "sub") {
                return args[0] - args[1];
            } else if (funcName == "mul") {
                return args[0] * args[1];
            } else if (funcName == "div") {
                return args[0] / args[1];
            } else if (funcName == "pow") {
                return pow(args[0], args[1]);
            } else if (funcName == "sqrt") {
                return sqrt(args[0]);
            } else {
                throw runtime_error("Unknown function: " + funcName);
            }
        }
    }

    return evalVar(ss);  // If not a function, check for variables
}


vector<double> parseArgs(stringstream& ss) {
    vector<double> args;
    while (ss.peek() != ')') {
        args.push_back(evalExp(ss));  // Evaluate arguments correctly (including variables)
        if (ss.peek() == ',') {
            ss.get();  // Consume ','
        }
    }
    return args;
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