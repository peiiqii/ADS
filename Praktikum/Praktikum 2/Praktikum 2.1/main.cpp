/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "?> ";
}

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
    int input;
    Ring myRing;
    string description, data;

    while (true) {
        print_menu();
        cin >> input;

        switch (input) {
        case 1:
            cout << "+Neuen Datensatz anlegen" << endl
                << " Beschreibung ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, description);
            cout << " Daten ";
            getline(cin, data);
            myRing.addNewNode(description, data);
            cout << "+Ihr Datensatz wurde hinzugefügt." << endl;
            break;

        case 2:
            cout << "+Nach welchen Daten soll gesucht werden?" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, data);
            if (myRing.search(data) == false) {
                cout << "Datensatz konnte nicht gefunden werden." << endl;
            }
            break;

        case 3:
            myRing.print();
            break;

        default:
            system("Pause");
            return 0;
        }
    }
   
	//
	///////////////////////////////////////
	system("Pause");
	return result;
}
