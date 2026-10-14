#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions{eListCurrency=1 , eFindCurrency=2 , eUpdateRate=3 , eCurrencyCalculator=4 , eExit=5};
	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "\tChoose What Do You Want To Do ? [ 1 To 5 ]: ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5,  "Please Enter Number From 1 To 5");
		return Choice;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "nPress Any Key To Return To Main Mneue Screen.";
		system("pause>0");
		ShowCurrencyMainScreen();
	}

	static void _ShowAllCurrencyScreen()
	{
		clsCurrencyListScreen::ShowAllCurrencyScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
	clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListCurrency:
		{
			system("cls");
			_ShowAllCurrencyScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
		
		}

		}
	}
public:
	static void ShowCurrencyMainScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Main Menue\n");
		cout << setw(37) << left << "" << "=============================================\n\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Main Menue\n\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency .\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate .\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator .\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue .\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformCurrencyMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

