#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCounter = 0;
        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << (3- FaildLoginCounter) 
                    << "Trial(s)f to login.\n\n";
            }
            if (FaildLoginCounter == 3)
            {
                cout << "You are locked after 3 faild trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;
            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();
            if (LoginFaild)
                FaildLoginCounter++;

        } while (LoginFaild);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t   Login Screen");
        _Login();
        return _Login();
    }

};

