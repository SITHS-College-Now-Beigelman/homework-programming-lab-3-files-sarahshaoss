//Sarah Shao
//10/15/2024
//Homework 3 Part 2

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    double total;
    char character;
    double number;
    double amountofWithdrawals = 0;
    double amountofDeposit = 0;

    ifstream inFile;
    ofstream outFile;

    inFile.open("transactions.txt");
    outFile.open("endBalance.txt");

    inFile >> total;
    outFile << fixed << setprecision(2) << "STARTING BALANCE: $" << total << endl << endl << endl;
    outFile << "TYPE" << setfill('.') << setw(12) << "AMOUNT" << setw(27) << "BALANCE" << endl;

    while (!inFile.eof())
    {
        inFile >> character >> number;
        if (character == 87)
        {
            total = total - number;
            outFile << character << setw(15) << number << setw(27) << total << endl;
            amountofWithdrawals = amountofWithdrawals + number;
        }
        else if (character = 68)
        {
            total = total + number;
            outFile << character << setw(15) << number << setw(27) << total << endl;
            amountofDeposit = amountofDeposit + number;
        }

    }

    outFile << "\n\nENDING BALANCE: $" << total << endl;
    outFile << "TOTAL WITHDRAWALS: $" << amountofWithdrawals << endl;
    outFile << "TOTAL DEPOSITS: $" << amountofDeposit << endl;

    return 0;
}