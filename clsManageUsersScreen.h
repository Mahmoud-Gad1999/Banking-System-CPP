#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h";
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"





using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUsersOption{eListUsers=1 , eAddNewUsers=2 , eDeleteUsers=3 , eUpdateUsers=4 , eFindUsers=5,eMainMenue=6};

	static  short _ReadManageUserMenueOption()
	{
		cout << setw(37) << left << "" << "\tChoose What Do You Want to do ? [ 1 to  6] ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Invalind Number , This Number Is Not Between 1 to 6 ");
		return Choice;
	}

	static void _GoBackToManageUsersMenueScreen()
	{
		cout << "\n\nPress Any Key To Return To Manage Users Screen\n";
		system("pause>0");
		ShowManageUsersMenueScreen();
	}

	static void _ShowAllListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUsersScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();

	}

	static void _ShowFindUsersScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerfromManageUsersMenueOption(enManageUsersOption Option)
	{
		switch (Option)
		{
		case enManageUsersOption::eListUsers:
		{
			system("cls");
			_ShowAllListUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		}
		case enManageUsersOption::eAddNewUsers:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		}
		case enManageUsersOption::eDeleteUsers:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		}
		case enManageUsersOption::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		}
		case enManageUsersOption::eFindUsers:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		}
		case enManageUsersOption::eMainMenue:
		{
			
		}
		}
	}

public:
	static void ShowManageUsersMenueScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		
		_DrawScreenHeader("\t\tManage User Menue\n");
		cout << setw(37) << left << "" << "=============================================\n\n";
		cout << setw(37) << left << "" << "\t\t\tManage User  Menue\n\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User .\n";
		cout << setw(37) << left << "" << "\t[3] Delete User .\n";
		cout << setw(37) << left << "" << "\t[4] Update User .\n";
		cout << setw(37) << left << "" << "\t[5] Find User .\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue .\n";
	
		cout << setw(37) << left << "" << "=============================================\n";
		_PerfromManageUsersMenueOption((enManageUsersOption)_ReadManageUserMenueOption());


	}
};

