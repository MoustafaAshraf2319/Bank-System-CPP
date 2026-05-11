#include <iostream>
#include <fstream>
#include "clsLoginScreen.h"
#include "clsDate.h"
using namespace std;
#include "Global.h"

clsUser CurrentUser = clsUser::Find("", "");

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen()) // give false  (!true)
        {
            break;
        }
    }

    return 0;
}

