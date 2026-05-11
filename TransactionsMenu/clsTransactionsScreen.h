#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions
	{
		eDeposit=1,eWithdraw=2,eShowTotalBalances=3,
		eTransfer=4,eTransferLog=5, eShowMainMenue = 6
	};
	static short _ReadTransactionsMenueOptions()
	{
		
		cout << setw(37) << left <<  "Choose what do you want to do From [1 to 6] ?" << endl;
		short n = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number Between 1,6\n");
		return n;
	}
	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdarwlScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsShowTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n Press any key to go back to menue screen" << endl;
		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions Trans)
	{
		switch (Trans)
		{
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdarwlScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowMainMenue:
		{
			
		}
		}
	}
public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t  Transacions Screen");
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdrawl.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================\n";
		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOptions());
	}
};

