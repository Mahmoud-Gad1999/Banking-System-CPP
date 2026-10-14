#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsUtil.h"


class clsUser:public clsPerson
{
private:
	

	enum enMode{EmptyMode=0 , UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete=false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUserData = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stoi(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string DataLine = "";
		DataLine += User.FirstName + Seperator;
		DataLine += User.LastName + Seperator;
		DataLine += User.Email + Seperator;
		DataLine += User.Phone +Seperator;
		DataLine += User.UserName + Seperator;
		DataLine +=  clsUtil::EncryptText(User.Password + Seperator);
		DataLine += to_string(User.Permissions);
		return DataLine;

	}



	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "","", 0);
	}

	static vector<clsUser>_LoadUserDataFromFile()
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveUserDataToFile(vector<clsUser>vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			string DataLine;
			for (clsUser& User : vUsers)
			{
				if (User._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine<<endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser>vUsers = _LoadUserDataFromFile();
		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUsers);
	}

	void _AddUserDataToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddUserDataToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareLogInRecord(string Seperator="#//#")
	{
		string DataLine = "";
		DataLine += clsDate::GetSystemDataTimeString()+Seperator;
		DataLine += UserName + Seperator;
		DataLine += clsUtil::EncryptText(Password + Seperator);
		DataLine += to_string(Permissions);
		return DataLine;
	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string>LoginRegisterDataLine= clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password =clsUtil::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permission = stoi(LoginRegisterDataLine[3]);
		return LoginRegisterRecord;
	}

	
//-------------------------------------------------------------------------------------------------------

	
public:
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permission;
	};
	
	enum enPermissions
	{
		eAll=-1 , pListClients=1 , pAddNewClient=2,pDeleteClient=4,pUpdateClient=8 , pFindClient=16,
		pTrnasactions=32 , pManageUsers=64,pLoginRegister=128
	};

	clsUser(enMode Mode,string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
		:clsPerson(FirstName , LastName , Email , Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}


	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName&&User.Password==Password)
				{
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
				return enSaveResults::svFaildAccountNumberExists;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}
	}

	bool Delete()
	{
		vector<clsUser>_vUsers = _LoadUserDataFromFile();
		for (clsUser& User : _vUsers)
		{
			if (User.UserName == _UserName)
			{
				User._MarkForDelete = true;
				break;
			}
		}
		_SaveUserDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser>GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		if ((this->Permissions & Permission) == Permission)
			return true;
		else
			return false;
	}

	 void RegisterLogIn()
	{
		string DataLine = _PrepareLogInRecord();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	 static vector<stLoginRegisterRecord>GetLoginRegisterList()
	 {

		 vector<stLoginRegisterRecord>vLoginRegisterRecord;
		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string Line;
			 stLoginRegisterRecord Register;
			 while (getline(MyFile, Line))
			 {
				 Register = _ConvertLoginRegisterLineToRecord(Line);
				 vLoginRegisterRecord.push_back(Register);
			 }
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;
	 }

};

