//Sarah Shao
//10/15/2024
//Homework 3 Part 1

#include <iostream> //includes libraries
#include <fstream>

using namespace std; // shortcut

int main()
{
    double total;
    //creates variable for total amount of money
    char character;
    //creates variable for the character of withdrawal or deposit
    double number;
    //creates variable for withdrawal or deposits
    int i;
    //loop counter

    ifstream inFile;
    //creates input file
    ofstream outFile;
    //creates output file

    inFile.open("transactions.txt");
    //opens input file
    outFile.open("endBalance.txt");
    //opens output file

    inFile >> total;
    //reads first number from input file and assigns it to total
    outFile << "The balance before the transactions: " << total << endl;
    //prints the balance before the transactions

    for (i = 0; i < 7; i++)
    //loops 7 times because there are 7 transactions
    {
        inFile >> character >> number;
        //reads the character and number
        if (character == 87)
        //if the character is a 'W'
        {
            total = total - number;
            //subtracts the number from the total
            cout << "Balance after this withdrawal: " << total << endl;
            //prints the balance after the withdrawal in terminal
        }

        else if (character == 68)
        //if the character is a 'D'
        {
            total = total + number;
            //adds the number to the total
            cout << "Balance after this deposit: " << total << endl;
            //prints the balance after the deposit in terminal
        }
    }
    outFile << "Balance after transactions: " << total << endl;
    //prints the balance after the transactions



    return 0; //ends program

/*  Terminal:
    Balance after this withdrawal: 4800
    Balance after this withdrawal: 4000
    Balance after this withdrawal: 3960
    Balance after this deposit: 4050
    Balance after this deposit: 4150
    Balance after this deposit: 5150
    Balance after this withdrawal: 513 */

    /* endBalance.txt
    The balance before the transactions: 5000
    Balance after transactions: 5130 */

    
}
