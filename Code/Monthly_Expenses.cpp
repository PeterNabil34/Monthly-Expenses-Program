#include <iostream>
#include<fstream>
#include "functions.cpp"
#include "classes.cpp"
using namespace std;

int main()
{   
   

    cout << "$$$ Welcome to Monthly Expense Program $$$\n";
    cout << "------------------------------------------\n";
    int Wallet_Index = choose_wallet();
    int choice;
    while (true)
    {
        cout << "------------------------------------------\n";
        cout << "------------------------------------------\n";
        cout << "1. Enter Monthly Income\n";
        cout << "2. Enter Daily Expenses\n";
        cout << "3. View Your Expenses\n";
        cout << "4. View Remaining Money\n";
        cout << "5. Save and Exit\n";
        cout << "Your Choice: ";     cin >> choice;

        switch (choice)
    {
        case 1:
        {
            monthly_income(Wallet_Index);
            break;
        }

        case 2:
        {
            daily_expenses(Wallet_Index);
            break;
        }

        case 3:
        {
            view_expenses();
            break;
        }

        case 4:
        {
            view_money();
            break;
        }

        case 5:
        {   
            saveDate();
            cout << "Your data has been saved, Goodbye\n";
            return 0;
        }
        default:
        {
            cout << "Invalid Choice\n";
        }
        
    }
  }

    return 0;
}
