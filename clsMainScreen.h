#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsBankClient.h"
//Screens
#include"clsScreen.h";
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsUser.h"
#include "Global.h"
#include"clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"

using namespace std;
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions{eListClients=1 , eAddNewClient=2 , eDeleteClient=3,eUpdateClient=4 , eFindClient=5,eShowTransactionsMenue=6,eManageUsers=7,eLoginRegister=8,eCurrencyExchange=9,eExit=10};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What Do You Wnat To Do ? [ 1 to 10 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number Between 1 to 10 ? ");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout <<setw(37) <<left<<""<<"nPress Any Key To Return To Main Mneue Screen.";
		system("pause>0");
		ShowMainMenueScreen();
	}
	
	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowAllClient();
	}

	static void _ShowAddNewClientsScreen()
	{
		
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientsScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientsScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientsScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
    }

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionMenue();
    }

	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenueScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrecnyMainScreen()
	{
		clsCurrencyMainScreen::ShowCurrencyMainScreen();
	}

	static void _Login()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();

			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrecnyMainScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Login();
			break;
		}
		
		}
	}
public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Menue\n");
		cout << setw(37) << left << "" << "=============================================\n\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client .\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client .\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info .\n";
		cout << setw(37) << left << "" << "\t[5] Find Client .\n";
		cout << setw(37) << left << "" << "\t[6] Transactions .\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users .\n";
		cout << setw(37) << left << "" << "\t[8] Login Register .\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange .\n";
		cout << setw(37) << left << "" << "\t[10] Logout .\n";


		cout << setw(37) << left << "" << "=============================================\n";
		_PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

		}
};

