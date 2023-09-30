#include <iostream>
#include <string>

using namespace std;

/*  @author [Dylan Cusson](https://github.com/dylancusson)
 *  @brief The Ultimate Binary Watch from SoCal ICPC 2021
 *  @details
 *  The Ultimate Binary Watch is a maker project that uses small LEDs to display the time on a watch
 *  face. The display uses four columns of four LEDs each, with each column representing a digit of the current
 *  time in hours and minutes. Time is displayed in 24-hour format, with the left-most column displaying the
 *  tens position for hours, the next column displaying the ones position for hours, the next column displaying
 *  the tens position for minutes, and the right-most column displaying the ones position for minutes. The
 *  bottom LED of each column is the low-order bit, with the bit positions increasing moving up the column.
 *  For example, the time 1615 would be displayed as shown in Figure 1.
 *  Your team is to write a program that will take a series of 24-hour times and print the corresponding
 *  watch faces. Input is a list of one to sixty valid 24-hour times, each on a separate line beginning in the first
 *  column. The input list ends with the end-of-file.
 *  For each time in the input, your program is to print the time on a line starting in the first column,
 *  followed by four lines with a representation of the watch face displaying that time. The tens of hours is
 *  to be in the first column, the single hours in the third, the tens of minutes in the seventh, and the single
 *  minutes in the ninth. Use asterisks to represent bits that are set and periods to represent bits that are clear.
 *  Columns not used are to be filled with spaces. No extra whitespace is to appear at the beginning or end of
 *  any output line.
*/
// Function to convert a decimal number to binary
string decimalToBinary(int num, int bits) {
    string binary = "";
    // Starting with the most significant bit because our output later is built top-down
    for (int i = bits - 1; i >= 0; i--) {
        if (num & (1 << i)) {   // Check if the i-th bit is set (1)
            binary += "*";      // If set, add an asterisk (*) to the binary representation
        } else {
            binary += ".";      // If not set, add a period (.) to the binary representation
        }
    }
    return binary;
}

int main() {
    string time;

    // While cin >> variable is similar to but safer than while !(cin.eof())
    while (cin >> time) {
        // stoi is a built in string to integer function
        // we use .substr to get the digits we want
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(2, 2));
        
        string tensHours = decimalToBinary(hours / 10, 4);
        string onesHours = decimalToBinary(hours % 10, 4);
        string tensMinutes = decimalToBinary(minutes / 10, 4);
        string onesMinutes = decimalToBinary(minutes % 10, 4);
        
        // Print the time
        cout << time << endl;
        
        // Print the watch face display
        for (int i = 0; i < 4; i++) {
            cout << tensHours[i] << " " << onesHours[i];
            cout << "   " << tensMinutes[i] << " " << onesMinutes[i] << endl;
        }
    }
    
    return 0;
}
