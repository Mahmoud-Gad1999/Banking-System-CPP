#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\tDelete Client Screen\n");
		cout << "\nEnter Account Number : ";
			string AccountNumber = "";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nThis Client Is Not Found , Please Enter Account Number :  \n";
		AccountNumber = clsInputValidate::ReadString();

	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	
	_PrintClient(Client);
	char Answer = 'n';
	cout << "\nAre You Sure Delete This Client Y/N :  ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
	{
		if (Client.Delete())
		{
			cout << "\nDelete This Client Successfully\n";
			_PrintClient(Client);

		}
		else
		{
			cout << "Do Not Delete This Client \n";
		}
	}
	}
};

