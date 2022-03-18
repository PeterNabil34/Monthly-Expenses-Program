#pragma once
#include <iostream>
using namespace std;

class wallet {
public:
    string name;
    string type;
    double money;

    wallet() {                                            //defualt constructor for wallet
        name = "Default";
        type = "Cash";
        money = 1000;
    }
    wallet(string n, string t, double m) {
        name = n;
        type = t;
        money = m;
    }
    ~wallet() {}
};

class expenses{
public:
    string category;
    string date;
    double cost;
    wallet Wallet;                                        // adding wallet element in expenses class to help in filtering by wallet

    expenses(string cat, string d, double c, wallet wal){
        category = cat;
        date = d;
        cost = c;
        Wallet = wal;
    }
    void display(){
        cout << "You spent " << cost << " in " << category << " on " << date << endl;
    }
    
    ~expenses(){}
};


