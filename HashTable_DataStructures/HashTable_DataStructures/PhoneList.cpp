#include "MyHash.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
/*Arayüz iþlemlerinin gerçekleþtiði ve kullanýcýdan yapmak istediði iþlemleri alan ve buna göre
gerekli fonksiyonlarý çaðýran main iþlemleri. */

using namespace std;


char choose;


char Option_show() {

    system("cls");
    cout << "******************************************";

    cout << "\nOption:" << endl;
    cout << "1:Add a person on my list" << endl;
    cout << "2:Delete a person on my list" << endl;
    cout << "3:Edit a person on my list" << endl;
    cout << "4:Show my list" << endl;
    cout << "5:Search a person on my list" << endl;
    cout << "6:Add extra number" << endl;
    cout << "7:Add extra e-mail" << endl;
    cout << "Q:Exit" << endl;

    cout << "Please select an option:";
    cin >> choose;

    return choose;

}


char return_ch() {

    char ch;
    bool sec = false;
    cout << "\n" << "1:Main Scream Q:Exit:";
    char secim;
    cin >> secim;


    if (secim == '1') {

        ch = Option_show();
        return ch;


    }

    else if (secim == 'Q' || secim == 'q') {

        ch = 'Q';
        return ch;

    }

    else {
        while (!sec) {
            cout << "Wrong selection.Try again" << endl;

            cout << "1:Main Scream Q:Exit:";
            cin >> secim;
            if (secim == 'Q' || secim == 'q' || secim == '1') {
                sec = true;

                if (secim == '1') {

                    ch = Option_show();
                    return ch;

                }
                else {
                    ch = 'Q';
                    return ch;
                }
            }
        }
    }

}


string isim;
string soyisim;
string adres;
string mail;
string telnum;
char secim;

int main()
{

    /*Main içerisinde menü sürekli olarak gösterilecek ve kullanýcý Q'ya basmadýðý sürece sonsuz döngüde kalacak
    Kullanýcý istediði iþleme göre giriþ yapýp seçime göre struct içindeki fonksiyon parametreleri alýnacak ve
    gerekli iþlemelr gerçekleþtirilecek.

    */


    list myList;
    myList.takeFromtext();

    bool sec = false;
    char ch = Option_show();
    bool sec2 = false;


    if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == 'Q' || ch == 'q') {


    }

    else {
        while (!sec2) {
            cout << "Wrong selection.Please again enter " << endl;
            ch = Option_show();
            if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == 'Q' || ch == 'q') {
                sec2 = true;

            }
        }
    }




    while (1) {

        if (ch == '1') {
            system("cls");

            cout << "Please enter " << endl;
            cout << "Name:";
            cin.ignore(256, '\n');
            getline(cin, isim);
            cout << endl;
            cout << " Surname:";
            getline(cin, soyisim);
            cout << endl;
            cout << " Address:";
            getline(cin, adres);
            cout << endl;
            cout << " E-mail:";
            getline(cin, mail);
            cout << endl;
            cout << "Phone number:";
            getline(cin, telnum);
            // cout << endl;
            myList.AddItemList(isim, soyisim, adres, mail, telnum);
            ch = return_ch();

        }
        else if (ch == '2') {
            system("cls");

            string del_person;
            //linked_list::display(a.gethead());
            cout << "Enter person name you want to delete:" << endl;
            cin.ignore(256, '\n');
            cin >> del_person;

            myList.deletePerson(del_person);
            ch = return_ch();

        }
        else if (ch == '3') {
            system("cls");



            string edit_person;
            int i = 0;
            string new_stat;
            bool slc = false;
            cout << "Please enter name you want edit:";
            cin.ignore(256, '\n');
            getline(cin, edit_person);
            cout << "Which one do you want change?" << endl;
            cout << "1:Name" << endl;
            cout << "2:Surname" << endl;
            cout << "3:Addr" << endl;
            cout << "4:Mail" << endl;
            cout << "5:Phone" << endl;
            cin >> i;

            if (i < 1 || i>5) {
                while (!slc) {
                    cout << "Wrong selection.Please write a number beetween 1 and 5";
                    cin >> i;

                    if (i > 0 && i < 6) {
                        slc = true;
                    }
                }

            }
            cout << "Write new state" << endl;
            cin.ignore(256, '\n');
            getline(cin, new_stat);

            while (new_stat == "") {
                cout << "You can not enter empty.Please again:" << endl;
                cin.ignore(256, '\n');
                getline(cin, new_stat);


            }
            myList.editPerson(edit_person, new_stat, i);


            ch = return_ch();


        }


        else if (ch == '4') {
            system("cls");

            myList.ShowList();
            ch = return_ch();

        }

        else if (ch == '5') {
            system("cls");

            string search;
            char option;
            bool sec = false;
            while (!sec) {

                cout << "What do you want search\n1:Name\n2:Number" << endl;
                cin >> option;
                if (option == '1' || option == '2') {

                    sec = true;

                }

                else
                    cout << "Wrong selection. Please enter again..." << endl;
            }
            if (option == '1') {
                cout << "Enter name you want search:" << endl;
                cin.ignore(256, '\n');

                getline(cin, search);

            }
            else {
                cout << "Enter a number you want to search(First Num) :" << endl;
                cin.ignore(256, '\n');
                getline(cin, search);
            }
            myList.FindPerson(search, option);

            ch = return_ch();
        }

        else if (ch == '6') {


            system("cls");


            string name;
            string new_number;
            char secim;
            cout << "Enter name you want to add phone number:";
            cin >> name;
            while (name == " " || name == "\n") {

                cout << "Wrong entry.Please enter a name again:";
                cin >> name;

            }
            cout << "Enter new phone number:";
            cin >> new_number;
            while (new_number == " " || new_number == "\n") {

                cout << "Wrong entry.Please enter a number again:";
                cin >> name;

            }

            myList.addExtra(name, new_number, 1);
            ch = return_ch();

        }

        else if (ch == '7') {



            system("cls");


            string name;
            string new_number;
            char secim;
            cout << "Enter name you want to add mail:";
            cin >> name;
            while (name == " " || name == "\n") {

                cout << "Wrong entry.Please enter a name again:";
                cin >> name;

            }
            cout << "Enter new mail:";
            cin >> new_number;
            while (new_number == " " || new_number == "\n") {

                cout << "Wrong entry.Please enter a mail again:";
                cin >> name;

            }

            myList.addExtra(name, new_number, 2);
            ch = return_ch();

        }


        else if (ch == 'Q') {

            cout << "GoodBy. We'll miss you...";
            myList.writeTex();
            break;
        }
        else if (ch == 'q') {

            cout << "GoodBy. We'll miss you...";
            myList.writeTex();

            break;
        }

        else {
            system("cls");
            cout << "Wrong selection...\n";
            ch = Option_show();

        }


    }
    return 0;
}
