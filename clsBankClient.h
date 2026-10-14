#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
using namespace std;
class clsBankClient :public clsPerson
{
private:
	//Client Mode 
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	//Data Member
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	// _ConvertLineToClientObject Method
	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	//_ConvertClientObjectToLine
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string DataLine = "";
		DataLine += Client.FirstName + Seperator;
		DataLine += Client.LastName + Seperator;
		DataLine += Client.Email + Seperator;
		DataLine += Client.Phone + Seperator;
		DataLine += Client.AccountNumber() + Seperator;
		DataLine += Client.PinCode + Seperator;
		DataLine += to_string(Client.AccountBalance);
		return DataLine;
	}

	//_GetEmptyClientObject Method
	static clsBankClient  _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	//Load Client Data From File
	static vector<clsBankClient>_LoadClientDataFromFile()
	{
		fstream MyFile;
		vector<clsBankClient>vClients;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;

	}

	//_SaveClientsDataToFile
	static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankClient& C : vClients)
			{
				if (C._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	//Update
	void _Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);

	}

	//Add New
	void _AddNew()
	{

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	//Add Data Line To File
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{
		string DataLine = "";
		DataLine += clsDate::GetSystemDataTimeString() + Seperator;
		DataLine += AccountNumber() + Seperator;
		DataLine += DestinationClient.AccountNumber() + Seperator;
		DataLine += to_string(Amount) + Seperator;
		DataLine += to_string(AccountBalance) + Seperator;
		DataLine += to_string(DestinationClient.AccountBalance) + Seperator;
		DataLine += UserName;
		return DataLine;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	struct stTrnsferLogRecord;

	static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		stTrnsferLogRecord TrnsferLogRecord;

		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);

		TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		return TrnsferLogRecord;

	}






	//----------------------------------------------------------------------------------------

public:

	struct stTrnsferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};
	//Constructer
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber , string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_PinCode = PinCode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
	}

	//Get , Account Number
	string AccountNumber()
	{
		return _AccountNumber;
	}

	//Get , Set Pin Code
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	//Get , Set Account Balance
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	
	//Print Client
	void Print()
	{
		cout << "\nCard Client : ";;
		cout << "\n---------------------------------------";
		cout << "\nFirst Name      : " << FirstName;
		cout << "\nLast Name       : " << LastName;
		cout << "\nFull Name       : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAccount Number  : " << _AccountNumber;
		cout << "\nPin Code        : " << _PinCode;
		cout << "\nAccount Balance : " << _AccountBalance;
		cout << "\n---------------------------------------\n";



	}

	//IsEmpty Client
	 bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	 //Find Client
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();

	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.PinCode==PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();

	}

	//Is Client Exist
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

    //Save
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
			break;

		}

		case enMode::UpdateMode:
		{


			_Update();

			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}

	}

	//GetAddNewClientObject
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{

		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	//Delete
	bool Delete()
	{
		vector<clsBankClient>vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject();
		return true;
	}
	
	//GetClientsList
	static vector<clsBankClient>GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	//Get Total Balance
	static double GetTotalBalances()
	{
		double TotalBalance = 0;
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		for (clsBankClient& C : vClients)
		{
			TotalBalance += C.AccountBalance;
		}

		return TotalBalance;
	}
     
	//Deposit
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	//Withdraw
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}

	}

	//Transfer
	bool Transfer(float Amount, clsBankClient& DestinationClient,string UserName)
	{
		if (Amount > AccountBalance)
			return false;
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(Amount, DestinationClient, UserName);
			return true;
		}

	}


	static  vector <stTrnsferLogRecord> GetTransfersLogList()
	{
		vector <stTrnsferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransfersLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stTrnsferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{

				TransferRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);

			}

			MyFile.close();

		}

		return vTransferLogRecord;

	}

	
};


