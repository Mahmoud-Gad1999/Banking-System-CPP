#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\n\n\nCard User : ";;
		cout << "\n---------------------------------------";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull Name       : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nAccount Number  : " << User.UserName;
		cout << "\nPin Code        : " << User.Password;
		cout << "\nAccount Balance : " << User.Permissions;
		cout << "\n---------------------------------------\n\n\n";
	}

public:
	static void ShowDeleteUserScreen()
	{
		system("cls");

		_DrawScreenHeader("\t     Delete User Screen");

		string UserName = "";

		cout << "Enter User Name : ";

		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nThis User Is Not Found , Please Enter Another User Name : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char Answer;
		cout << "\n\nAre You Sure Do You Want Delete This User Y/N : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully\n";
				_PrintUser(User);
			}
			else
			{
				cout << "User Deleted Not Successfully\n";
			}

		}
		else
		{
			cout << "\nOk , Thank You \n";
		}

		
	}
};

