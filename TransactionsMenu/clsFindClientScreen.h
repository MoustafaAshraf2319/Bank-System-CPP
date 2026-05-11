#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n Client Catd : ";
		cout << "\n----------------";
		cout << "\nFirst Name : " << Client.FirstName;
		cout << "\nLast Name  : " << Client.LastName;
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email;
		cout << "\nPhone      : " << Client.Phone;
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nPassword   : " << Client.PinCode;
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n----------------\n";
	}
public:
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty())
		{
			cout << "Client Found" << endl;
		}
		else
		{
			cout << "Client was Not Found" << endl;
		}
		_PrintClient(Client1);

	}

};
