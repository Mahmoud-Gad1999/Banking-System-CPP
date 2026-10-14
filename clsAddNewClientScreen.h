#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h";
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
private:
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
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nCard Client : ";;
		cout << "\n---------------------------------------";
		cout << "\nFirst Name      : " <<Client.FirstName;
		cout << "\nLast Name       : " <<Client.LastName;
		cout << "\nFull Name       : " <<Client.FullName();
		cout << "\nEmail           : " <<Client.Email;
		cout << "\nPhone           : " <<Client.Phone;
		cout << "\nAccount Number  : " <<Client.AccountNumber();
		cout << "\nPin Code        : " <<Client.PinCode;
		cout << "\nAccount Balance : " <<Client.AccountBalance;
		cout << "\n---------------------------------------\n";
	}
public:
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
		string AccountNumber = "";
		cout << "Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Client Is Already Found , Please Enter Another Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		//_PrintClient(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nUpdated Successfully\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nClient Is Empty\n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "This Client Is Exists\n";
			break;
		}

		}
	}
};

