//Sarah Shao
//10/15/2024
//Homework 3 Part 2

#include <iostream> //include libraries
#include <fstream>
#include <iomanip>

using namespace std; //shortcut

int main()
{
    double total;
    //creates a variable for total amount of money
    char character;
    //creates a variable for the character of withdrawal or deposit
    double number;
    //creates a variable for the number of withdrawal or deposit money
    double amountofWithdrawals = 0;
    //creates a variable to calculate the amount of money withdrawed
    double amountofDeposit = 0;
    //creates a variable to calculate the amount of money deposited

    ifstream inFile;
    //creates a variable for the input file
    ofstream outFile;
    //creates a variable for the output file

    inFile.open("transactions.txt");
    //opens the input file
    outFile.open("endBalance.txt");
    //opens the output file

    inFile >> total;
    //reads the first number in the input file and assigns it to the variable total
    outFile << fixed << setprecision(2) << "STARTING BALANCE: $" << total << endl << endl << endl;
    //outputs the starting balance to the output file. Organizes it with 2 lines of spaces and shows 2 decimal points after
    outFile << "TYPE" << setfill('.') << setw(12) << "AMOUNT" << setw(27) << "BALANCE" << endl;
    //outputs whether its a withdrawal or deposit, then the amount of withdrawal and deposit, and then the balance after these transactions. Filled with "."s.

    while (!inFile.eof())
    //while the input file is not at the end of the file
    {
        inFile >> character >> number;
        //reads the character and number from the file and assigns them to the variables character and number
        if (character == 87)
        //if the character is 'W'
        {
            total = total - number;
            //subtracts the number from the total
            outFile << character << setw(15) << number << setw(27) << total << endl;
            //outputs the character, the number, and the total, separated by "."s and lined up to match the amount and balance
            amountofWithdrawals = amountofWithdrawals + number;
            //adds the number to the amount of money withdrawed
        }
        else if (character == 68)
        //if the character is 'D'
        {
            total = total + number;
            //adds the number to the total
            outFile << character << setw(15) << number << setw(27) << total << endl;
            //outputs the character, the number, and the total, separated by "."s and lined up to match the amount and balance
            amountofDeposit = amountofDeposit + number;
            //adds the number to the amount of money deposited
        }

    }

    outFile << "\n\nENDING BALANCE: $" << total << endl;
    //outputs the ending balance to the output file. Organizes it with 2 lines of spaces before.
    outFile << "TOTAL WITHDRAWALS: $" << amountofWithdrawals << endl;
    //outputs the total amount of money withdrawed to the output file.
    outFile << "TOTAL DEPOSITS: $" << amountofDeposit << endl;
    //outputs the total amount of money deposited to the output file.

    return 0; //ends program
}
