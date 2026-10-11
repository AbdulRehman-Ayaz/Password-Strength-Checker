#include<iostream>
#include<string>
using namespace std;

int main() {
    string password;
    bool hasNumber = false;
    bool hasCapital = false;
    bool hasSmall = false;
    bool hasSymbol = false;
    bool hasSeq = false;
    int counter = 0;

    cout << "=== PASSWORD STRENGTH CHECKER ===" << endl;
    cout << "Enter your password: ";
    cin >> password;

    char ch;
    for (int i = 0; i < password.length(); i++) {
        ch = password[i];
        if (ch >= '0' && ch <= '9') {
            hasNumber = true;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            hasCapital = true;
        }
        else if (ch >= 'a' && ch <= 'z') {
            hasSmall = true;
        }
        else if (ch == '#' || ch == '@' || ch == '%' || ch == '!' || ch == '&' || ch == '$') {
            hasSymbol = true;
        }
    }

    if (password.find("123") != string::npos ||
        password.find("456") != string::npos ||
        password.find("789") != string::npos) {
        hasSeq = true;
    }

    if (hasNumber) counter++;
    if (hasCapital) counter++;
    if (hasSmall) counter++;
    if (hasSymbol) counter++;
    if (hasSeq) counter--;

    if (counter == 4) {
        cout << "Strong Password" << endl;
    }
    else if (counter == 3) {
        cout << "Medium Password" << endl;
    }
    else if (counter == 2) {
        cout << "Lower Medium Password" << endl;
    }
    else {
        cout << "Weak Password" << endl;
    }

    return 0;
}
