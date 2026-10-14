#include <iostream>
#include<fstream>
#include<iomanip>
#include "clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsCurrency.h"
#include"clsLoginScreen.h"

using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}
	system("pause>0");
}




