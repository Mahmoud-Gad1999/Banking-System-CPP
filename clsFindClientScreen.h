#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsFindClientScreen:protected clsScreen
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber = "";
		cout << "Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
			cout << "\nClient Found -)\n";
		else
			cout << "\nClient Was Not Found -(\n";
		_PrintClient(Client);

	}
};

