#include <iostream>
#include<fstream>
#include <vector>
#include<sstream>
#include "classes.cpp"
using namespace std;

vector<wallet> w;
vector<expenses> ex;

vector <expenses> filterByDate(vector<expenses> ex) {
    string filter_date;
    vector <expenses> filtered_vector;
    cout << "Enter the Date you want to filter with(dd/mm/yy): ";
    cin >> filter_date;
    for (int i = 0; i < ex.size(); i++) {
        if (ex[i].date == filter_date)
            filtered_vector.push_back(ex[i]);
    }
    return filtered_vector;
}
vector <expenses> filterByCategory(vector<expenses> ex) {
    string filter_Category;
    vector <expenses> filtered_vector;
    cout << "Enter the Category you want to filter with: ";
    cin >> filter_Category;
    for (int i = 0; i < ex.size(); i++) {
        if (ex[i].category == filter_Category)
            filtered_vector.push_back(ex[i]);
    }
    return filtered_vector;
}
vector <expenses> filterByAmount(vector<expenses> ex) {
    double filter_amount;
    vector <expenses> filtered_vector;
    cout << "Enter the amount you want to filter with: ";
    cin >> filter_amount;
    for (int i = 0; i < ex.size(); i++) {
        if (ex[i].cost == filter_amount)
            filtered_vector.push_back(ex[i]);
    }
    return filtered_vector;
}
vector <expenses> filterByWalletName(vector<expenses> ex) {
    string wallet_Name;
    vector <expenses> filtered_vector;
    cout << "Enter the wallet name: ";
    cin >> wallet_Name;
    for (int i = 0; i < ex.size(); i++) {
        if (ex[i].Wallet.name == wallet_Name)
            filtered_vector.push_back(ex[i]);
    }
    return filtered_vector;
}
vector <expenses> filterByWalletType(vector<expenses> ex) {
    string wallet_Type;
    vector <expenses> filtered_vector;
    cout << "Enter the wallet type: ";
    cin >> wallet_Type;
    for (int i = 0; i < ex.size(); i++) {
        if (ex[i].Wallet.type == wallet_Type)
            filtered_vector.push_back(ex[i]);
    }
    return filtered_vector;
}

int choose_wallet()
{
    wallet w1;
    w.push_back(w1);
    int choice;
    while (true)
    {
        int wallet_choice;
        cout << "Choose a Wallet\n";
        cout << "1. Existing Wallet\n";
        cout << "2. New Wallet\n";
        cout << "Your Choice: ";     cin >> choice;
        if(choice == 1){
            if(w.empty())
                cout << "No Wallets to display\n";
            else{
                cout << "Choose Between These Wallets\n";
                for(int i=0; i<w.size(); i++){
                    cout << "Wallet "<< i+1 << ": Name " << w[i].name << " of Type " << w[i].type<< endl;
                    cout << "-----------------------------------------------------------------------\n";
                }
                cout << "Press 0 to Return\n";
                cout << "Your Choice: ";        cin >> wallet_choice;
                if(wallet_choice == 0)
                {
                    continue;
                }
                else if(wallet_choice < 0 || wallet_choice >w.size())
                {
                    cout << "Invalid Choice\n";
                }
                else
                    return wallet_choice-1;
            }
        }
        else if(choice ==2){
            cout << "Enter Wallet name: ";       string Name;        cin >> Name;
            cout << "Enter Wallet type: ";       string Type;        cin >> Type;
            cout << "Enter amount of money in the Wallet: ";       double Money;        cin >> Money;
            wallet w2(Name, Type, Money);
            w.push_back(w2);
        }
        else
            cout << "Invalid Choice\n";
            cout<<"----------------------------------"<<endl;
            cout<<"Press 1 to continue or 0 to return"<<endl;
            cout<<"----------------------------------"<<endl;
            cin>>choice;
            if(choice == 1)
               continue;
            else if(choice == 0)
               break;
            
            
    }
}

void monthly_income(int wal_ind)
{
    cout << "Enter Your Monthly Income: ";
    int mon_income;      cin >> mon_income;
    w[wal_ind].money += mon_income;
    cout << "This Wallet now contains: " << w[wal_ind].money << " Dollars\n";
}

void daily_expenses(int wal_ind)
{
    cout << "Enter The Category: ";         string Category;        cin >> Category;
    cout << "Enter The Date: ";         string Date;        cin >> Date;
    cout << "Enter The Cost: ";         double Cost;        cin >> Cost;
    wallet Wallet = w[wal_ind];
    expenses e1(Category, Date, Cost, Wallet);
    if(Wallet.money - e1.cost < 0)
        cout << "There is No Enough Money Left\n";
    else 
    {
        Wallet.money -= e1.cost;
        //w[wal_ind].money -= e1.cost;
        ex.push_back(e1);
    }
}

void view_expenses()
{
    int exp_choice;
    while(true)
    {
        cout << "------------------------------------------\n";
        cout << "------------------------------------------\n";
        cout << "1. View All Expenses\n";
        cout << "2. Filter By Date\n";
        cout << "3. Filter By Category\n";
        cout << "4. Filter By Amount\n";
        cout << "5. Apply Many Filters\n";
        cout << "6. Filter By Wallet\n";
        cout << "7. Exit\n";
        cout << "Your Choice: ";        cin >> exp_choice;
        switch(exp_choice)
        {
            case 1:
            {
                if (ex.empty())
                    cout << "No expenses to Display.\n";
                else {
                    cout << "------------------------------------------\n";
                    for(int i=0; i<ex.size(); i++){
                        ex[i].display();
                    }
                }
                break;
            }

            case 2:
            {
                vector<expenses> filtered_expenses;
                filtered_expenses = filterByDate(ex);
                if (filtered_expenses.empty())
                    cout << "No Data Has been Found.\n";
                else
                {
                    cout << "------------------------------------------\n";
                    for (int i = 0; i < filtered_expenses.size(); i++)
                        filtered_expenses[i].display();
                }
                break;
            }

            case 3:
            {
                vector<expenses> filtered_expenses;
                filtered_expenses = filterByCategory(ex);
                if (filtered_expenses.empty())
                    cout << "No Data Has been Found.\n";
                else
                {
                    cout << "------------------------------------------\n";
                    for (int i = 0; i < filtered_expenses.size(); i++)
                        filtered_expenses[i].display();
                }
                break;
            }

            case 4:
            {
                vector<expenses> filtered_expenses;
                filtered_expenses = filterByAmount(ex);
                if (filtered_expenses.empty())
                    cout << "No Data Has been Found.\n";
                else
                {
                    cout << "------------------------------------------\n";
                    for (int i = 0; i < filtered_expenses.size(); i++)
                        filtered_expenses[i].display();
                }
                break;
            }

            case 5:
            {
                int filters;
                vector <expenses> filtered_expenses;

                cout << "How many filter do you want to apply: "; cin >> filters; //geting the number of filters he wants to use
                int* arr = new int[filters];                                    

                cout << "Choose the filters:\n1.Date.\n2.Category.\n3.cost.\n4.wallet Name.\n5.wallet Type.\n";
                cout << "Your choices: ";
                for (int i = 0; i < filters; i++)
                    cin >> arr[i];                                      //choosing the filters and putting it's number in dynamic array

                for (int i = 0; i < ex.size(); i++)        //copying the orignal expenses vector into another one to be able to mainpulte with it
                    filtered_expenses.push_back(ex[i]);

                for (int i = 0; i < filters; i++) {         //according to each filter selected we use it's function
                    if (arr[i] == 1)

                        filtered_expenses = filterByDate(filtered_expenses);
                        
                    else if (arr[i] == 2)
                    
                        filtered_expenses = filterByCategory(filtered_expenses);
                    
                    else if (arr[i] == 3)
                    
                        filtered_expenses = filterByAmount(filtered_expenses);
                    
                    else if (arr[i] == 4)
                    
                        filtered_expenses = filterByWalletName(filtered_expenses);
                    
                    else if (arr[i] == 5)
                    
                        filtered_expenses = filterByWalletType(filtered_expenses);
                    
                }
                if (filtered_expenses.empty())
                {
                    cout << "No Data Has been found\n";
                }
                else
                {
                    cout << "------------------------------------------\n";
                    for (int i = 0; i < filtered_expenses.size(); i++)
                        filtered_expenses[i].display();
                }


                break;
            }
            case 6:
            {
                int wallet_choice;
                bool found = false;
                cout << "Do you want to filter with\n1.Wallet Name\n2.Wallet Type\n";
                cout << "Choice: "; cin >> wallet_choice;

                if (wallet_choice == 1)
                {
                    vector<expenses> filtered_expenses;
                    filtered_expenses = filterByWalletName(ex);
                    if (filtered_expenses.empty())
                        cout << "No Data Has been Found.\n";
                    else
                    {
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < filtered_expenses.size(); i++)
                            filtered_expenses[i].display();
                    }
                }
                else if (wallet_choice == 2)
                {
                    vector<expenses> filtered_expenses;
                    filtered_expenses = filterByWalletType(ex);
                    if (filtered_expenses.empty())
                        cout << "No Data Has been Found.\n";
                    else
                    {
                        cout << "------------------------------------------\n";
                        for (int i = 0; i < filtered_expenses.size(); i++)
                            filtered_expenses[i].display();
                    }
                }
                else
                    cout << "Invlaid Choice\n";
                break;
            }
            case 7:
                return;
            default:
            {
                cout << "Invalid Choice\n";
            }
        }
    }

}

void view_money()
{
    int wallet_choice;
    cout << "Choose Between These Wallets\n";
    for(int i=0; i<w.size(); i++){
        cout << "Wallet "<< i+1 << ": Name " << w[i].name << " of Type " << w[i].type<< endl;
        cout << "-----------------------------------------------------------------------\n";
    }
    cout << "Your Choice: ";        cin >> wallet_choice;
    if(wallet_choice <= 0 || wallet_choice >w.size())
        cout << "Invalid Choice\n";
    else
        cout << "You Have " << w[wallet_choice-1].money << " Left in this Wallet\n";

}


void saveDate()
{ 
  ofstream Data("Monthly Expenses.txt",ios::app);
  fstream ReadData("Read.txt",ios::in|ios::out|ios::app);
  string line ;
  double total_cost = 0.0;
  double total_money = 0.0 ;
  double c = 0.0;
  
  Data<<"----------------------------------------------------"<<endl;
  Data<<"|             Data oF Monthly Expenses             |"<<endl;
  Data<<"----------------------------------------------------"<<endl;
  for(int i = 0 ;i<ex.size(); i++)
  { 
    
    Data<<"You spent " << ex[i].cost << " in " << ex[i].category << " on " << ex[i].date << endl;
    total_cost+=ex[i].cost;

  }

    ReadData<<total_cost<<endl;
    ReadData.seekg(0,ios::beg);
    while(!ReadData.eof())
    {
      getline(ReadData,line);
      for(int i = 0 ;i<line.length();i++)
        c = c *10 +(line[i]-'0');
        total_money+=c;
        c = 0.0; 
    }

    Data<<endl;
    Data<<"---------------------------------------------------"<<endl;
    Data<<"|               Data oF Wallets                   |"<<endl;
    Data<<"---------------------------------------------------"<<endl; 

  for(int i = 0 ;i<w.size(); i++)
  { 
    Data<<"--------------------------------------"<<endl;
    Data<<w[i].name<<" of Type "<<w[i].type<<" Contains "<< w[i].money-total_money<<" Dollars"<<endl;;
    Data<<"---------------------------------------"<<endl;
  }
  

   Data<<"------------------------------------------------------------------------------------------"<<endl;


  Data.close();
  ReadData.close();


}
