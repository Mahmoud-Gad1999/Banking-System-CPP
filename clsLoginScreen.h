#pragma once
#include <iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsMainScreen.h"

#include"Global.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short LoginFaildCount = 0;
		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				LoginFaildCount++;
				cout << "\nyou Have ( " << (3 - LoginFaildCount) << " ) Trail(s)\n";

			}
			if (LoginFaildCount == 3)
			{
				cout << "\nYou Finshed After 3 Trails\n";
				return false;
			}
			
			cout << "\nEnter User Name : ";
			cin >> UserName;
			cout << "\nEnter Password : ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		 
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenueScreen();
		return true;
	}



public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();

    }
};

