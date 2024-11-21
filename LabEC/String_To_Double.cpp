// HS fall 2024

#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>

// Add this line to avoid repeating std::
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const string& str);

int main() {
    string input;
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);
        
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}



double extractNumeric(const string& str){
    double count = 0;
    bool decimalReached = false;
    bool isNegative = false;
    double decimalMultiplier = 1;

    for(int i = 0; i < str.length(); i++){
        char cur = str[i];
        
        if('0' <= cur && cur <= '9'){
            if(!decimalReached){
                count = count * 10 + (cur - '0');
            }else{
                count = count + (cur - '0') * decimalMultiplier;
                decimalMultiplier *= 0.1;
            }
        }else if(cur == '.'){
            if(!decimalReached){
                decimalReached = true;
                decimalMultiplier = 0.1;
            }else{
                return -999999.99;
            }
        }else if(cur == '-'){
            isNegative = true;
        }else if(cur == '+'){
            // do nothing
        }else{
            return -999999.99;
        }
    }

    if(isNegative){
        count *= -1;
    }
    return count;
}