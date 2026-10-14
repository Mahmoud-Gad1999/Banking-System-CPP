#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsUpdateClientScreen:protected clsScreen
{
private :
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
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Enter Pin Code : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
public:
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen\n");
			string AccountNumber = "";
	cout << "Enter Account Number : ";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nIs Client Is Not Found , Please Enter Another Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	_PrintClient(Client);

	char Answer;
	cout << "\nAre You Sure Update This Client Y/N : ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
	{
		cout << "\n--------------------\n";
		cout << "Update Client : ";
		cout << "\n--------------------\n";

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nUpdated Successfully\n";
			_PrintClient(Client);
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nClient Is Empty\n";
			break;
		}

		}


	}
	}
	
};

