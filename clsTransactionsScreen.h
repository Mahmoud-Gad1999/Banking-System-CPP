#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h";
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include "clsTransferLogScreen.h";

using namespace std;


class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionMenue{eDeposit=1 , eWithdraw=2, eTotalBalance=3,eTransfer=4,eTransferLog=5,eMainMenue=6};
	static short _ReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "Choose What Do You Wnat To Do ? [ 1 to 6 ] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,6,"Enter Between 1 To 6");
		return Choice;
	}

	static void _GoBackToTransactionMenue()
	{
		cout << "\nPress Any Key To Return Transaction Menue\n";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepsitScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static  void _PerfromTransactionMenueOption(enTransactionMenue Option)
	{
		switch (Option)
		{
		case enTransactionMenue::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenue::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenue::eTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenue::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenue::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionMenue::eMainMenue:
		{
			
		}
		}
	}
public:
	static void ShowTransactionMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTrnasactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tTransactions Menue\n");
		cout << setw(37) << left << "" << "=============================================\n\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw .\n";
		cout << setw(37) << left << "" << "\t[3] Totla Balance .\n";
		cout << setw(37) << left << "" << "\t[4] Transfer .\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log .\n";
		cout << setw(37) << left << "" << "\t[6] MainMenue .\n";


		
		cout << setw(37) << left << "" << "=============================================\n";
		_PerfromTransactionMenueOption((enTransactionMenue)_ReadTransactionMenueOption());
	}
};

