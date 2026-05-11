#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsShowTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static double ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\n Enter Transfer Amount ?";
		Amount = clsInputValidate::ReadNumber<float>();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available balance, Enter amount\n";
			Amount = clsInputValidate::ReadNumber<float>();
		}
		return Amount;
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease enter AccountNumber to Transfer From : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account number is not found, choose another one\n";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);


		double Amount = ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this opertion? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\n Transfer done Successfully.\n";
			}
			else
			{
				cout << "Transfer Faild\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}

};

