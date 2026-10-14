#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<ctime>
#include "clsString.h"
#include"clsDate.h"
using namespace std;
class clsUtil
{
public:
	enum enOpType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5 };
	static void  Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static char GetRandomCharacter(enOpType Type)
	{
		if (Type == enOpType::MixChars)
		{
			Type = (enOpType)RandomNumber(1, 3);
		}
		switch (Type)
		{
		case enOpType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
		}
		case enOpType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
		}
		case enOpType::Digit:
		{
			return char(RandomNumber(48, 57));
		}
		case enOpType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
		}
		default:
			return char(RandomNumber(65, 90));

		}
	}

	static string GenerateWord(enOpType Type, short Length)
	{
		string Word = "";
		for (short i = 0; i < Length; i++)
		{
			Word += GetRandomCharacter(Type);
		}
		return Word;
	}

	static string GenerateKey(enOpType Type)
	{
		string Key = "";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4) + "-";
		Key += GenerateWord(Type, 4);
		return Key;


	}

	static void GenerateKeys(short Number, enOpType Type)
	{
		for (short i = 1; i <= Number; i++)
		{
			if (i < 10)
				cout << "Key [" << i << "]  : " << GenerateKey(Type) << endl;
			else
				cout << "Key [" << i << "] : " << GenerateKey(Type) << endl;

		}
	}

	static void Swap(int& A, int& B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void Swap(string& S1, string& S2)
	{
		string Temp;
		Temp = S1;
		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void ShuffleArray(int Arr[], short Length)
	{
		for (short i = 0; i < Length; i++)
		{
			Swap(Arr[RandomNumber(1, Length) - 1], Arr[RandomNumber(1, Length) - 1]);
		}
	}

	static void ShuffleArray(string Arr[], short Length)
	{
		for (short i = 0; i < Length; i++)
		{
			Swap(Arr[RandomNumber(1, Length) - 1], Arr[RandomNumber(1, Length) - 1]);
		}
	}

	static void FillArrayWithRandomNumber(int Arr[], short Length, short From, short To)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string Arr[], short Length, enOpType Type, short WordLength)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = GenerateWord(Type, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string Arr[], short Length, enOpType Type)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = GenerateKey(Type);
		}
	}

	static string Tabs(short Number)
	{
		string Text = "";
		for (short i = 0; i < Number; i++)
		{
			Text += "\t";
		}
		return Text;
	}

	static string EncryptText(string Text, short Key=2)
	{


		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) + Key);
		}
		return Text;
	}

	static string DecryptText(string Text, short Key=2)
	{

		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = char(int(Text[i]) - Key);
		}
		return Text;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

	

	



};


