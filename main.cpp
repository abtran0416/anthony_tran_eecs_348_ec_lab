#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>
#include <cmath>

// Add this line to avoid repeating std::
using namespace std;


double extractNumeric(const string& str){ 
    int length = str.length();
    bool number_started = false;
    bool is_negative = false;
    bool has_decimal = false;
    bool is_first_digit = false;
    double result = 1.0;
    double multiplier = (length-1);
    

    if (length <= 20){
        for (char c : str){
            //Reads as if the c (a character of str) is - and if number_started is false, 
            //if it is updates the is_negative variable to be true and 
            //starts the count for number
            if (c == '-' && !number_started){
                is_negative = true; 
                number_started = true;
            }
            //Reads as if the c (a character of str) is + and if number_started is false,
            //Bascially checks to see if the first character, c is a plus
            else if (c == '+' && !number_started){
                is_negative = false;
                number_started = true;
            }
            //This if checks to see if it is a digit, and if it is it has to make sure
            //that the count of the number starts and to update the double variables
            else if (isdigit(c)){
                number_started = true;
                //This part is checking if the character equals a decimal point or not
                //If it is we have to multiply it by the negative digits 
                if (!has_decimal){
                    if (multiplier == (length - 1)){
                        result *= ((c-0) * pow(10,multiplier));
                        multiplier -= 1;
                    }
                    else if (multiplier <= (length -1)){
                        result += ((c-0) * pow(10, multiplier));
                        multiplier -= 1;
                    }
                }
                else{
                    result += ((c-0) * pow(10, multiplier));
                    multiplier -= 1;
                }
            }
            //This portion right here checks to see if it is a decimal point or not
            else if (c == '.'){
                has_decimal = true;
                multiplier -= 1;
            }
            else{
                return (-999999.99);
            }
        }
  
    }
    //Retuns back input is invalid
    else{
        return (-999999.99);
    }
    return (is_negative ? - result : result);
}

int main() {
    string input;
    while (true){
        cout <<"Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END"){
            break;
        }

        double number = extractNumeric(input);
        
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." <<endl;
        }
    }
    
    return 0;
}