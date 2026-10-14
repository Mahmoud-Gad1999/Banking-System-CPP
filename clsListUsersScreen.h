#pragma once
#include<iostream>
#include<iomanip>
//Screen
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;
class clsListUsersScreen:protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		 cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}
public:
	static void ShowUsersList()
	{
		vector<clsUser>vUsers = clsUser::GetUsersList();
		string Title = "\tUsers List Screen";
		string SubTitle = "\t ( " + to_string(vUsers.size()) + " ) User(s). ";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "FullName";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vUsers.size() == 0)
		{
			cout << "Not Client AValibale In This System\n";
		}
		else
		{
			for (clsUser& User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
	
};

