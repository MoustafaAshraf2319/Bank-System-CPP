#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>
class clsManageUsersScreen :protected clsScreen
{
private:
	enum enManageUsersOptions{mListUsers=1,mAddNewUser=2,mDeleteUser=3,
	mUpdateUser=4,mFindUser=5,mMainMenu=6};
	static short _ReadUserChoice()
	{
		cout << setw(37) << left << "Choose What do you want to do From [1 to 6]" << endl;
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Number is within range");
		return Choice;
	}
	static void _GoBackToManageUsersMenueScreen()
	{
		cout << "\t\tPress any key to go back to manage users menue screen ";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _ShowListUsersScreen()
	{
		//cout << "\n List Users will be here\n";
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		//cout << "\n Add New Users will be here\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//cout << "\n Delete Users will be here\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//cout << "\n Update Users will be here\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		//cout << "\n Find Users will be here\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenueOptions(enManageUsersOptions ManageUsers)
	{
		switch (ManageUsers)
		{
		case enManageUsersOptions::mListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enManageUsersOptions::mAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enManageUsersOptions::mDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enManageUsersOptions::mUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enManageUsersOptions::mFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enManageUsersOptions::mMainMenu:
		{
			
		}

		}
	}

public:
	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\t Manage Users Screen");
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users\n";
		cout << setw(37) << left << "" << "\t[2] Add New User\n";
		cout << setw(37) << left << "" << "\t[3] Delete User\n";
		cout << setw(37) << left << "" << "\t[4] Update User\n";
		cout << setw(37) << left << "" << "\t[5] Find User\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		_PerformManageUsersMenueOptions((enManageUsersOptions)_ReadUserChoice());
	}

	
};

