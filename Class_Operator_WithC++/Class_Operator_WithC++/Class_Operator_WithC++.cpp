// Class_Operator_WithC++.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include<string>
#include "Operator.h"
using namespace std;

int main()
{
    BankAccount myAccount(1000, "10001000");
    BankAccount yourAccount;
    
    yourAccount.setMoney(300);
    yourAccount.setAccountID("102311000");
    
    cout << "My total money is " << myAccount.getMoney() << endl;
    cout << "Your total money is" << yourAccount.getMoney() << endl;
   
    BankAccount totalAccount;
    totalAccount = myAccount.operator+(yourAccount);
    cout << "Our total money:" << totalAccount.getMoney() << endl;
    
    
    BankAccount differAccount;
    differAccount = myAccount.operator-(yourAccount);
    cout << "Our money difference is:" << differAccount.getMoney()<<endl;

    if (myAccount.operator==(yourAccount))
    {
        cout << "We have same amount of money..." << endl;
    }
    else
        cout << "We have not same amount of money..." << endl;

    if (myAccount.operator>(yourAccount))
       
        cout << "I have got money more than you" << endl;
   
    else
        cout << "You have got money more than me" << endl;

    myAccount.depositMoney(550);
    yourAccount.takeMoney(150);

    if (myAccount.operator==(yourAccount))
    {
        cout << "We have same amount of money..." << endl;
    }
    else
        cout << "We have not same amount of money..." << endl;


    //With Operators

    BankAccount totalAccountOperator = myAccount + yourAccount;
    cout <<"Operator total money:" <<totalAccountOperator.getMoney()<<endl;
   
    if (myAccount == yourAccount)
    {
        cout << "Equal money" << endl;

    }

    

    myAccount.depositMoney(50);
    yourAccount.takeMoney(100);

    if (myAccount > yourAccount)
    {
        cout << "My money is bigger than yours..." << endl;
    }

    else
        cout << "You have got a lot money than me...";



}
