/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:
void menu()
{
    cout<< "====================================" << endl
        << " ADS - ELK - Stack v1.9, by 25th Bam" << endl
        << "====================================" << endl 
        << "1) Datensatz einfuegen, manuell" << endl
        << "2) Datensatz einfuegen, CSV Datei" << endl
        << "3) Datensatz loeschen" << endl
        << "4) Suchen" << endl
        << "5) Datenstruktur anzeigen" << endl
        << "6) Level-Order Ausgabe" << endl
        << "7) Beenden" << endl;
}

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
            "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
        {
            cout << "Fehler beim Lesen!" << endl;
            return;
        }
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}

//
///////////////////////////////////////
int main()
{

    int result = Catch::Session().run();

    //Tree t;
    Tree* t = new Tree();
    int eingabe;
    string name = "";
    int age = 0, postcode = 0;
    double income = 0.0;
    int NodeOrderID = 0;
    
    while (1)
    {
        menu();
        cout << "?>";
        cin >> eingabe;
        cout << endl;
        cin.ignore();
        cin.clear();

        switch (eingabe)
        {
        case 1:
            cout << "+ Bitte geben Sie die den Datensatz ein:" << endl;
            cout << "Name ?> ";
            getline(cin, name);
            cout << "Alter ?> ";
            cin >> age;
            cout << "Einkommen ?> ";
            cin >> income;
            cout << "PLZ ?> ";
            cin >> postcode;
            t->addNode(name, age, income, postcode);
            cout << "+ Ihr Datensatz wurde eingefuegt." << endl << endl;
            break;

        case 2:
            mainscreen_addTreeCSV(t);
            break;

        case 3:
            cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl;
            cout << "OrderID ?> ";
            cin >> NodeOrderID;
            t->deleteNode(NodeOrderID);
            cout << "+ Eintrag wurde geloescht." << endl << endl;
            break;

        case 4:
            cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
            cout << "Name ?> ";
            getline(cin, name);
            cout << "+ Fundstellen: " << endl;
            if (!t->searchNode(name))
            {
                cout << "Nicht gefunden." << endl << endl;
            }
            cout << endl;
            break;

        case 5:
            t->printAll();
            cout << endl;
            break;

        case 6:
            t->levelOrder();
            cout << endl;
            break;

        case 7:
            return 0;
        }
    }
    system("PAUSE");

    return 0;
}