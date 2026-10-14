#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h";
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"Global.h"

using namespace std;
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "\n-------------------------\n";
		cout << "\nFull Name : " << Client.FullName();
		cout << "\nAccount Number : " << Client.AccountNumber();
		cout << "\nBalance : " << Client.AccountBalance;
		cout << "\n-------------------------\n";


	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number To Transfer To: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Client Is Not Found , Please Enter Another Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount = 0;
		cout << "Enter Transfer Amount : ";
		Amount = clsInputValidate::ReadFloatNumber();
		 while (Amount >SourceClient.AccountBalance)
		 {
			 cout << "\nThis Amount Is More Balance This Client Enter Anoter Amount : ";
			 Amount = clsInputValidate::ReadFloatNumber();

		 }
		return Amount;
		
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);


		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre You Sure You Want Perform This Operation Y/N : ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nDone Transfer Successfully\n";
			}
			else
			{
				cout << "\nDont Transfer\n";
			}
		}

		_PrintClientCard(SourceClient);

		_PrintClientCard(DestinationClient);

		
		
		
	}
};

