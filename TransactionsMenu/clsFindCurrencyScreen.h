#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
   

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode    : " << Currency.CurrencyCode();
        cout << "\nName   : " << Currency.CurrencyName();
        cout << "\nRate(1$) =     : " << Currency.Rate();
        cout << "\n___________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\n Currency Found:-)";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\n Currency was NOT Found:-(";
        }
    }


public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t   Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? \n";
        short Answer = 1;
        cin >> Answer;
        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\n Please enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\n Please enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(Country);
            _ShowResults(Currency);
        }
        
        
    }

};
