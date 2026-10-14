#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsAddNewUserScreen:protected clsScreen
{
private:
	static short _ReadPermissionsToSet()
	{
	   short Permission = 0;
		char Answer = 'n';

		cout << "\nDo You Wnat To Give Full Access ? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer=='y')
		{
			return -1;
		}

		cout << "\nDo You Wnat To Give access to : \n";

		cout << "\nShow Client List Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			 Permission += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pTrnasactions;
		}

		cout << "\nManage Users Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pLoginRegister;
		}

		return Permission;

	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name : ";
		User.LastName= clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		User.Email= clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		User.Phone= clsInputValidate::ReadString();
		cout << "\nEnter Password : ";
		User.Password= clsInputValidate::ReadString();
		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionsToSet();

	}

	static void _PrintUser(clsUser User)
	{
		cout << "\n\n\nCard User : ";;
		cout << "\n---------------------------------------";
		cout << "\nFirst Name      : " <<User.FirstName;
		cout << "\nLast Name       : " <<User.LastName;
		cout << "\nFull Name       : " <<User.FullName();
		cout << "\nEmail           : " <<User.Email;
		cout << "\nPhone           : " <<User.Phone;
		cout << "\nUser Name  : " <<User.UserName;
		cout << "\nPassword       : " <<User.Password;
		cout << "\nPermission : " <<User.Permissions;
		cout << "\n---------------------------------------\n\n\n";
	}

public:

	static void ShowAddNewUserScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Add New User Screen");
		string UserName = "";
		cout << "Enter User Name Pleas : ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nThis User Is Found , Please Enter Anoter User Name : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\n\nUser Addeded Successfully :-) ";
			_PrintUser(NewUser);
			break;
             
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nNot Added This User It's Empty\n";
		}
		case clsUser::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\n\nErorr This User Is Found\n";
		}

		}


	}
};

