#ifndef OPERATOR_H
#define OPERATOR_H
#include<iostream>
#include<string>
#include <cmath>
using namespace std;


	class BankAccount
	{
	public:
		BankAccount();
		BankAccount(int moneynew, std::string accountIDnew);
		void depositMoney(int amount);
		void takeMoney(int amount);
		
		int getMoney() const;
		void setMoney(int amount);
		string getAccountID();
		void setAccountID(string ID);
		const BankAccount operator +(const BankAccount& account) const;
		const BankAccount operator -(const BankAccount& account) const ;
		bool  operator ==(const BankAccount& account) const;
		bool  operator >(const BankAccount& account) const;

	private:
		int money;
		string id;

	};






#endif