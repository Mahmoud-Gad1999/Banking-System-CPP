#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsFindUserScreen:protected clsScreen
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		string UserName = "";
		cout << "Enter User Name : ";
		UserName = clsInputValidate::ReadString();
		
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nThis User Name Is Not Found Please Enter Another User Name : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was Not Found :-(\n";
		}

	

		_PrintUser(User);

		

	}
};

