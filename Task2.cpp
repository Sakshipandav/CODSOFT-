#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Prompt user to enter two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Prompt user to choose an operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the chosen operation and display the result
    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            break;
    }

    return 0;
}
