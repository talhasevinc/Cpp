#include "Operator.h"
#include <string>
#include<iostream>
#include<cmath>
using namespace std;


	BankAccount::BankAccount()
		:money(0),id("No ID")
	{
	     //You can write any error or cause function.
	}

	BankAccount::BankAccount(int moneynew, string accountIDnew)
		: money(moneynew), id(accountIDnew)
	{
			if (moneynew < 0) 
			{
				cout << "Money can not be lower than 0";
				exit(1);

		    }
			money = moneynew;
			id = accountIDnew;
	}

	void BankAccount::setMoney(int amount)
	{
		money = amount;
	
	}

	int BankAccount::getMoney() const
	
	{
		return money;
	}

	string BankAccount::getAccountID()
	{

		return id;

	}

	void BankAccount::setAccountID(string ID)
	{
		id = ID;
	}

	void BankAccount::depositMoney(int amount)
	{
		if (money < amount)
		{

			cout << "You have not enough money..." << endl;
			
		}
		else {
			money -= amount;
			cout << "Your new money:" << money << endl;
		}
	}
	void BankAccount::takeMoney(int amount)
	{
		money += amount;
		cout << "Your new money:" << money << endl;
	}

	const BankAccount BankAccount::operator +(const BankAccount& account) const 
	{
		int totalMoney = 0;
		string newID="1111111111";
		totalMoney = money + account.money;
		return BankAccount(totalMoney, newID);
		
	}

	const BankAccount BankAccount::operator -(const BankAccount& account) const
	{
		int totalMoney = 0;
		string newID = "1111111111";
		totalMoney = money - account.money;
		return BankAccount(totalMoney, newID);

	}

	bool  BankAccount::operator ==(const BankAccount& account) const
	{
		if (money == account.getMoney())
		{
			return true;

		}
		else
			return false;

	}
	bool  BankAccount::operator >(const BankAccount& account) const
	{
		if (money > account.getMoney())
			return true;
		else
			return false;

	}

