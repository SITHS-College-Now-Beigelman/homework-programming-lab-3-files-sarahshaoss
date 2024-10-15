//Sarah Shao
//10/15/2024
//Homework 3 Part 1

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    double total;
    char character;
    double number;
    int i;

    ifstream inFile;
    ofstream outFile;

    inFile.open("transactions.txt");
    outFile.open("endBalance.txt");

    inFile >> total;
    outFile << "The balance before the transactions: " << total << endl;

    for (i = 0; i < 7; i++)
    {
        inFile >> character >> number;
        if (character == 87)
        {
            total = total - number;
            cout << "Balance after this withdrawal: " << total << endl;

        }
        
        else if (character == 68)
        {
            total = total + number;
            cout << "Balance after this deposit: " << total << endl;
        }
    }
    outFile << "Balance after transactions: " << total << endl;



    return 0;
}