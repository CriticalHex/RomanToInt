#include<iostream>

using namespace std;

class Solution {
public:
    string roman;
    int decimal = 0;
    Solution(string rom) {
        roman = rom;
        for (int i = 0; i < roman.length(); i++) {
            if (i < roman.length() - 1) {
                if ((roman[i + 1] == 'V' or roman[i + 1] == 'X') and roman[i] == 'I') { decimal -= 1; }
                else if ((roman[i + 1] == 'L' or roman[i + 1] == 'C') and roman[i] == 'X') { decimal -= 10; }
                else if ((roman[i + 1] == 'D' or roman[i + 1] == 'M') and roman[i] == 'C') { decimal -= 100; }
                else { decimal += rti(roman[i]); }
            }
            else { decimal += rti(roman[i]); }
        }
    }
    
    int rti(char c) {
        if (c == 'I') {
            return 1;
        }
        else if (c == 'V') {
            return 5;
        }
        else if (c == 'X') {
            return 10;
        }
        else if (c == 'L') {
            return 50;
        }
        else if (c == 'C') {
            return 100;
        }
        else if (c == 'D') {
            return 500;
        }
        else if (c == 'M') {
            return 1000;
        }
    }

};


int main() {
    string userIn;
    cout << "Enter a roman numeral: " << endl;
    cin >> userIn;
    Solution RTI(userIn);
    while (userIn != "0") {
        cout << "Enter 1 to print the Roman Numeral form, 2 to print the Decimal form, or 0 to quit: " << endl;
        cin >> userIn;
        if (userIn == "1") {
            cout << RTI.roman << endl;
        }
        else if (userIn == "2") {
            cout << RTI.decimal << endl;
        }
    }
}