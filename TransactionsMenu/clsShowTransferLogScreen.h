#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsShowTransferLogScreen : protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountFrom;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountTo;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.BalanceFrom;
        cout << "| " << setw(10) << left << TransferLogRecord.BalanceTo;
        cout << "| " << setw(8) << left << TransferLogRecord.Username;
        
    }
public:
    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(24) << "Date/Time";
        cout << "| " << left << setw(6) << "A.From";
        cout << "| " << left << setw(6) << "A.To";
        cout << "| " << left << setw(6) << "Amount";
        cout << "| " << left << setw(6) << "B.From";
        cout << "| " << left << setw(6) << "B.To";
        cout << "| " << left << setw(8) << "Username";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {
                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

