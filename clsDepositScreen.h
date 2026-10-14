#pragma once
#include<iostream>
#include<vector>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;

class clsDepositScreen:protected clsScreen
{

private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nCard Client : ";;
		cout << "\n---------------------------------------";
		cout << "\nFirst Name      : " << Client.FirstName;
		cout << "\nLast Name       : " << Client.LastName;
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAccount Number  : " << Client.AccountNumber();
		cout << "\nPin Code        : " << Client.PinCode;
		cout << "\nAccount Balance : " << Client.AccountBalance;
		cout << "\n---------------------------------------\n";
	}

public:
	static void ShowDepsitScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");
		string AccountNumber;
		cout << "Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Client Is Not Found , Please Enter Another Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\nPlease Enter Deposit Amount  : ";
		Amount = clsInputValidate::ReadDblNumber();
		char Answer;
		cout << "\n\nAre You Sure You Want Persfrom This Transaction : Y/N ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nDeposit This Client Successfully -) ";
			cout << "\nThis Client Account Balance Is : " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOk , Not Deposit This Client -( \n";
		}


	}
};

