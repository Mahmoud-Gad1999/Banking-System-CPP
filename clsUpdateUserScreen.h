#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsUpdateUserScreen:protected clsScreen
{
private:
	static short _ReadPermissionsToSet()
	{
		short Permission = 0;
		char Answer = 'n';

		cout << "\nDo You Wnat To Give Full Access ? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
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
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionsToSet();

	}
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
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen");

		string UserName = "";
		cout << "Enter User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\n\nThis User Is Not Found Please Enter Another User Name : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Answer = 'n';
		cout << "\nAre You Sure Update This User Y/N : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();
			switch (SaveResult)
			{
				case clsUser::enSaveResults::svSucceeded:
				{
					cout << "\n\nUser Updated Successfully :-) ";
					_PrintUser(User);
					break;

				}
				case clsUser::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nErorr , Not Update This User It's Empty\n";
				}
				case clsUser::enSaveResults::svFaildAccountNumberExists:
				{
					cout << "\n\nErorr This User Is Found\n";
				}
			}
		}
		else
		{
			cout << "\nOk , Thank You\n";
		}


	}
};

