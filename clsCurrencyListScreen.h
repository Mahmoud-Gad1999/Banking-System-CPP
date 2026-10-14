#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsCurrency.h"

using namespace std;
class clsCurrencyListScreen: protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(30) << left << Currency.CurrencyName();
		cout << "| " << setw(20) << left << Currency.Rate();
	}
public:
	static  void ShowAllCurrencyScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}
		vector<clsCurrency>vClients = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrency List Screen";
		string SubTitle = "\t ( " + to_string(vClients.size()) + " ) Currency(s). ";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(15) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)";
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vClients.size() == 0)
		{
			cout << "Not Client AValibale In This System\n";
		}
		else
		{
			for (clsCurrency& C : vClients)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};

