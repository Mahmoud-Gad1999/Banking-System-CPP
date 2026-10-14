#pragma once
#include <iostream>
#include "clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
class clsInputValidate
{

public:
	//Is Number Betweent
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	//IsDate Between
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) && (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
		{
			return true;
		}

		return false;


	}

	//Read Short Number && Read Short Number Between
	static short ReadShortNumber(string ErorrMessage = "Invalid Number , Enter Again\n")
	{
		short Number;
		

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;

		}
		return Number;
	}
	static short ReadShortNumberBetween(short From , short To , string ErorrMessage = "Invalid Number , Enter Again")
	{
		short Number = ReadShortNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErorrMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	//Read Int Number && Read Int Number Between
	static int ReadIntNumber(string ErorrMessage = "Invalid Number , Enter Again\n")
	{
		int Number = 0;
		
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;

		}
		return Number;

	}
	static int ReadIntNumberBetween(int From, int To, string ErorrMessage = "Number Is Not Within range , Enter Again : \n")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErorrMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	//ReadFloat Number && Read Float Number Between
	static float ReadFloatNumber(string ErorrMessage = "Invalid Number , Enter Again\n")
	{
		float Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;
		}
		return Number;
	}
	static float ReadFloatNumberBetween(float From, float To, string ErorrMessage = "Invalid Number , Enter Again")
	{
		float Number = ReadShortNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErorrMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	//Read Double Number && Read Double Number Between
	static double ReadDblNumber(string ErorrMessage = "Invalid Number , Enter Again\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;

		}
		return Number;

	}
	static double ReadDblNumberBetween(double From, double To, string ErorrMessage = "Number Is Not Within range , Enter Again : \n")
	{
		double Number;
		Number = ReadDblNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErorrMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	//Is Valid Date
	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	//Raed String
	static string ReadString()
	{
		string Text = "";
		getline(cin >> ws, Text);
		return Text;
	}




};

