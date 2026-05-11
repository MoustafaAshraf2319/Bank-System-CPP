#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsInputValidate.h"
#include "clsFindCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptions
	{
		cListCurrencies = 1, cFindCurrency = 2, cUpdateRate = 3, cCurrencyCalculator = 4, cMainMenue = 5
	};

	static short _ReadCurrencyExchangeMenueOptions()
	{
		short c;
		cout << setw(37) << "Choose what do you want to do from [1 to 5]\n";
		cin >> c;
		while (c < 1 || c>5)
		{
			cout << "Invaild choice, Please enter another choice from [1 to 5]\n";
			cin >> c;
		}
		return c;
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency Screen will be here";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "Update Rate Screen will be here";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "Currency Calculator Screen will be here";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMenueScreen()
	{
		cout << "\n Press any key to go back to menue screen" << endl;
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _PerformTransactionsMenueOptions(enCurrencyExchangeMenueOptions CurExOptions)
	{
		switch (CurExOptions)
		{
		case enCurrencyExchangeMenueOptions::cListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case enCurrencyExchangeMenueOptions::cFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case enCurrencyExchangeMenueOptions::cUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case enCurrencyExchangeMenueOptions::cCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenueScreen();
			break;
		}
		case enCurrencyExchangeMenueOptions::cMainMenue:
		{

		}
		}
	}

public:
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Currency Exchange Screen");
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calaculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================\n";
		_PerformTransactionsMenueOptions((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOptions());
	}
};

