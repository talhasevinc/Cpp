// Data_Structer_Project.cpp : Bu dosya 'main' iþlevi içeriyor. Program yürütme orada baþlayýp biter.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


using namespace std;
ofstream file_;

struct node
{   //Oluþturulacak her bir kiþinin hafýzada tutulacak nitelikleri tanýmlandý.
    string name;
    string surname;
    string address;
    string e_mail[4];
    string phone_number[4];
    node* next;
};

class linked_list
{ // Baþlangýç için bir baþ ve bir son eleman NULL olarak oluþturuldu. Yapýlacak iþleme göre deðiþimler gerçekleþecek.
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }


    void add_node(string n, string sn, string mail, string phone, string addr)
    { // Kiþi ekleneceði zaman main içerisinde girilen deðerler fonksiyona yollanacak ve gelen deðiþkenlere göre
            //yeni bir kiþi eklenecek.
        node* tmp = new node;
        tmp->name = n;
        tmp->surname = sn;
        tmp->address = addr;
        tmp->e_mail[0] = mail;
        tmp->phone_number[0] = phone;

        tmp->next = NULL;

        if (head == NULL) //Eðer baþ kýsým boþsa bu defterin boþ olduðu manasýna gelir.Eklenen eleman 1. kiþi olacaktýr.
        {
            head = tmp;
            tail = tmp;
        }
        else// Eðer liste boþ deðilse eklenen kiþi en sona eklenecek ve artýk kuyruk kýsmý olacaktýr.
        {
            tail->next = tmp;
            tail = tail->next;
        }

    }
    node* gethead()
    {
        return head;
    }


    static void display(node* head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            // Defteri gösterme kýsmý. Oluþturulan q deðiþkeni head'in gösterdiði kýsýmdan baþlayacak ve her seferinde
            //next ifadesi ile diðer elemana geçip onu ekrana basacaktýr. Ekstra girilen deðerler dolu olmasý durumunda
            //ekrana basýlacaktýr.

            node* q = NULL;
            q = head;

            while (q != NULL) {
                cout << "*************************************" << endl;
                cout << "Name:" << q->name << "\n" << "Surname:" << q->surname << "\n" << "Address:" << q->address << "\n" << "E-mails:" << q->e_mail[0];
                if (q->e_mail[1] != "")
                    cout << "," << q->e_mail[1];

                if (q->e_mail[2] != "")
                    cout << "," << q->e_mail[2];
                if (q->e_mail[3] != "")
                    cout << "," << q->e_mail[3];

                cout << " \nPhone Numbers:" << q->phone_number[0];
                if (q->phone_number[1] != "")
                    cout << "," << q->phone_number[1];
                if (q->phone_number[2] != "")
                    cout << "," << q->phone_number[2];
                if (q->phone_number[3] != "")
                    cout << "," << q->phone_number[3];

                cout << endl;


                q = q->next;

            }



        }
    }
    void  find_index(int index) {

        int i = 0;
        int say = 0;
        node* q = NULL;
        q = head;
        while (q != NULL) {

            if (i == index) {

                cout << "|" << q->name << " " << q->surname << endl;

            }
            q = q->next;
            i++;
        }


    }

    void edit_person(string nm, int i, string nw) {
        //Kullanýcý deðiþiklik yapacaðý kiþinin ismini girecek ve ardýndan hangi özelliði deðiþtireceðini seçecektir.
        //Head'dan baþlayarak kullanýcýnýn girdiði isim aranacak ve bulununca hangi niteliði deðiþtirmek istiyorsa onu
        //deðiþtirecektir.Ekstra bilgiler için ayrý bir sorgu daha gerçekleþtirilecek ve 1. 2. 3. hangisini deðiþtirmek
        //istiyorsunuz diye sorgulama yapýlacaktýr.
        struct node* q = NULL;
        node* one = NULL;
        char sec;
        q = head;
        int find[10];
        int choose = 0;
        int say = 0;
        int in = 0;
        while (q != NULL) {

            if ((q->name) == nm) {

                find[say] = in;
                say++;

                one = q;

            }
            q = q->next;
            in++;
        }
        if (say == 1) {
            q = one;
        }

        else if (say > 1) {

            for (int k = 0;k < say;k++) {
                cout << (k + 1);

                find_index(find[k]);
            }

            cout << "Which one do you want edit:";
            cin >> choose;
            q = head;
            in = 0;
            while (q != NULL) {
                if (find[choose - 1] == in) {

                    break;

                }
                q = q->next;
                in++;


            }


        }



        if (i == 1) {

            q->name = nw;
        }


        else if (i == 2) {
            q->surname = nw;

        }


        else if (i == 3) {

            q->address = nw;

        }

        else if (i == 4) {
            if (q->e_mail[1] != "" && q->e_mail[2] != "" && q->e_mail[3] != "") {
                cout << "Which one do you want edit?\n1:E_mail-1\n2:E_mail-2\n3:E_mail-3\n4:E_mail-4:";
                cin >> sec;
                if (sec == '1') {
                    q->e_mail[0] = nw;

                }

                else if (sec == '2') {
                    q->e_mail[1] = nw;

                }
                else if (sec == '3') {
                    q->e_mail[2] = nw;

                }
                else if (sec == '4') {
                    q->e_mail[3] = nw;

                }


            }
            else if (q->e_mail[1] != "" && q->e_mail[2] != "") {
                cout << "Which one do you want edit?\n1:E_mail-1\n2:E_mail-2\n3:E_mail-3:";
                cin >> sec;
                if (sec == '1') {
                    q->e_mail[0] = nw;

                }

                else if (sec == '2') {
                    q->e_mail[1] = nw;

                }
                else if (sec == '3') {
                    q->e_mail[2] = nw;

                }


            }
            else if (q->e_mail[1] != "") {
                cout << "Which one do you want edit?\n1:E_mail-1\n2:E_mail-2:";
                cin >> sec;
                if (sec == '1') {
                    q->e_mail[0] = nw;

                }

                else if (sec == '2') {
                    q->e_mail[1] = nw;

                }
            }

            else
                q->e_mail[0] = nw;



        }

        else if (i == 5) {

            if (q->phone_number[1] != "" && q->phone_number[2] != "" && q->phone_number[3] != "") {
                cout << "Which one do you want edit?\n1:Num-1\n2:Num-2\n3:Num-3\n4:Num-4:";
                cin >> sec;
                if (sec == '1') {
                    q->phone_number[0] = nw;

                }

                else if (sec == '2') {
                    q->phone_number[1] = nw;

                }
                else if (sec == '3') {
                    q->phone_number[2] = nw;

                }
                else if (sec == '4') {
                    q->phone_number[3] = nw;

                }


            }
            else if (q->phone_number[1] != "" && q->phone_number[2] != "") {
                cout << "Which one do you want edit?\n1:Num-1\n2:Num-2\n3:Num-3:";
                cin >> sec;
                if (sec == '1') {
                    q->phone_number[0] = nw;

                }

                else if (sec == '2') {
                    q->phone_number[1] = nw;

                }
                else if (sec == '3') {
                    q->phone_number[2] = nw;

                }



            }

            else if (q->phone_number[1] != "") {
                cout << "Which one do you want edit?\n1:Num-1\n2:Num-2:";
                cin >> sec;
                if (sec == '1') {
                    q->phone_number[0] = nw;

                }

                else if (sec == '2') {
                    q->phone_number[1] = nw;

                }

            }

            else {

                q->phone_number[0] = nw;

            }
        }
    }

    void tokenize(std::string const& str, const char delim,
        std::vector<std::string>& out)
    {
        //Texten veri okumak için yazýlan bir fonksiyon. Texin bütün bir satýrý okunuyor ve kullanýcýnýn istediði karaketere
        //göre string ler parçalanýyor. Bu sayede her bir kiþinin isim, soyisim ,numara gibi deðiþkenleri birbirine karýþmadan
        //tekrar programa çekiliyor.

        std::stringstream ss(str);

        std::string s;
        while (std::getline(ss, s, delim)) {
            out.push_back(s);
        }
    }

    void take_text() {
        //Program her açýldýðý zaman listemizin silinmemesi gerekiyor. busebeple kullanýcý ilk programý çalýþtýrdýðý zaman 
        // istediði kadar kiþi ekleyecek, program kapatýldýðýnda ise bu kiþiler otomatil olarak texte yazýlacak. Kullanýcý
        //programý tekrar çalýþtýrdýðý zaman ise bu tex içinde bulunan isimler ve bilgiler tekrardan sisteme yüklenecek.

        string line;

        node* tmp = new node;
        string info[11];
        //q = head;
        ifstream myfile("MyList.txt");
        if (myfile.is_open())
        {
            while (myfile.good())
            {
                int countt = 0;
                const char delim = ',';
                getline(myfile, line);

                std::vector<std::string> out;
                tokenize(line, delim, out);

                for (auto& line : out) {
                    if (countt == 0) {
                        info[0] = line;
                    }
                    else if (countt == 1) {
                        info[1] = line;
                    }

                    else if (countt == 2) {
                        info[2] = line;
                    }
                    else if (countt == 3) {
                        info[3] = line;
                    }
                    else if (countt == 4) {
                        info[4] = line;
                    }
                    else if (countt == 5) {
                        info[5] = line;
                    }
                    else if (countt == 6) {
                        info[6] = line;
                    }

                    else if (countt == 7) {
                        info[7] = line;
                    }
                    else if (countt == 8) {
                        info[8] = line;
                    }
                    else if (countt == 9) {
                        info[9] = line;
                        node* tmp = new node;
                        tmp->name = info[0];
                        tmp->surname = info[1];
                        tmp->address = info[2];
                        tmp->e_mail[0] = info[3];
                        tmp->e_mail[1] = info[4];
                        tmp->e_mail[2] = info[5];
                        tmp->e_mail[3] = info[6];

                        tmp->phone_number[0] = info[7];
                        tmp->phone_number[1] = info[8];
                        tmp->phone_number[2] = info[9];
                        tmp->phone_number[3] = info[10];

                        tmp->next = NULL;

                        if (head == NULL)
                        {
                            head = tmp;
                            tail = tmp;
                        }
                        else
                        {
                            tail->next = tmp;
                            tail = tail->next;
                        }


                    }
                    countt++;

                }

                countt = 0;
                // cout << line << endl;
            }
            cout << "Data received..." << endl;

            myfile.close();
        }

        else cout << "There is no list yet..." << endl;

    }

    void add_number(int index, string new_num) {

        //Kullanýcý menüden ekstra numara eklemesi yapacak.Bu kýsýmda extra numara isteniyor. Sýrasýyla hangi
        // numaranýn boþ olduðu bulunup oraya ekleme yapýlýyor. Eðer 3 exetra numara da doluysa ekleme yapamýyor.
        node* q = NULL;
        q = head;
        int i = 1;

        int counter = 1;

        while (q->next != NULL) {
            counter++;
            q = q->next;

        }

        if (counter <= index) {
            index = counter;

        }

        q = head;

        while (q != NULL) {

            if (i == index) {
                break;
            }
            else {
                i++;

                q = q->next;
            }
        }


        if (q->phone_number[1] == "") {

            q->phone_number[1] = new_num;


        }
        else if (q->phone_number[2] == "") {

            q->phone_number[2] = new_num;


        }
        else if (q->phone_number[3] == "") {

            q->phone_number[3] = new_num;


        }

        else
        {
            cout << "The limit is full.You can't add new number.";
        }


    }
    void add_mail(int index, string new_mail) {

        //Exetra mail ekleme kýsmý. Kullanýcý menüden exetra mail ekleme için giriþ yapýp mail adresini giriyor.
        node* q = NULL;
        q = head;
        int i = 1;
        int counter = 1;

        while (q->next != NULL) {
            counter++;
            q = q->next;

        }

        if (counter <= index) {
            index = counter;

        }

        q = head;

        while (q != NULL) {

            if (i == index) {
                break;
            }
            else {
                i++;

                q = q->next;
            }
        }

        if (q->e_mail[1] == "") {

            q->e_mail[1] = new_mail;


        }
        else if (q->e_mail[2] == "") {

            q->e_mail[2] = new_mail;


        }
        else if (q->e_mail[3] == "") {

            q->e_mail[3] = new_mail;


        }

        else
        {
            cout << "The limit is full.You can't add new mail.";
        }
    }

    void search_person(string name, char what) {
        //Kullanýcý veritabanýnda kiþi aramasý yapacak. Bu kýsýmda öncce isim ve ya numaradan arama yapma imkaný sunuluyor.
        //Devamýnda aramak istediði ismi ve ya numarayý yazýyor. Tamamýný girmesine gerek yok. Ýçesinde bulunan herhangi bir 
        //parçayý girebilir.

        node* q = NULL;
        q = head;
        bool tarama = true;

        if (head == NULL) {

            cout << " Your list is empty. Please add a person..." << endl;

        }

        else {

            if (what == '1') {
                while (q != NULL) {

                    if ((q->name).find(name) == string::npos) {

                    }

                    else {
                        cout << "*************************************" << endl;
                        cout << "Name:" << q->name << "\n" << "Surname:" << q->surname << "\n" << "Address:" << q->address << "\n" << "E-mails:" << q->e_mail[0];
                        if (q->e_mail[1] != "")
                            cout << "," << q->e_mail[1];

                        if (q->e_mail[2] != "")
                            cout << "," << q->e_mail[2];
                        if (q->e_mail[3] != "")
                            cout << "," << q->e_mail[3];

                        cout << " \nPhone Numbers:" << q->phone_number[0];
                        if (q->phone_number[1] != "")
                            cout << "," << q->phone_number[1];
                        if (q->phone_number[2] != "")
                            cout << "," << q->phone_number[2];
                        if (q->phone_number[3] != "")
                            cout << "," << q->phone_number[3];

                        cout << endl;


                    }

                    if (q->next == NULL) {

                        tarama = false;
                        break;

                    }

                    else {


                        q = q->next;
                    }

                }
            }
            else if (what == '2') {
                while (q != NULL) {

                    if ((q->phone_number[0]).find(name) != string::npos || (q->phone_number[1]).find(name) != string::npos || (q->phone_number[2]).find(name) != string::npos || (q->phone_number[3]).find(name) != string::npos) {


                        cout << "*************************************" << endl;
                        cout << "Name:" << q->name << "\n" << "Surname:" << q->surname << "\n" << "Address:" << q->address << "\n" << "E-mails:" << q->e_mail[0];
                        if (q->e_mail[1] != "")
                            cout << "," << q->e_mail[1];

                        if (q->e_mail[2] != "")
                            cout << "," << q->e_mail[2];
                        if (q->e_mail[3] != "")
                            cout << "," << q->e_mail[3];

                        cout << " \nPhone Numbers:" << q->phone_number[0];
                        if (q->phone_number[1] != "")
                            cout << "," << q->phone_number[1];
                        if (q->phone_number[2] != "")
                            cout << "," << q->phone_number[2];
                        if (q->phone_number[3] != "")
                            cout << "," << q->phone_number[3];

                        cout << endl;

                    }

                    if (q->next == NULL) {

                        tarama = false;
                        break;

                    }

                    else {
                        q = q->next;
                    }

                }



            }

        }
    }

    void write_text() {
        struct node* q = NULL;
        file_.open("MyList.txt");

        if (file_.is_open()) {
            q = head;
            while (q != NULL) {

                if (q->e_mail[1] == "") {
                    q->e_mail[1] == " ";

                }
                if (q->e_mail[2] == "") {
                    q->e_mail[2] == " ";

                }
                if (q->e_mail[3] == "") {
                    q->e_mail[3] == " ";

                }

                if (q->phone_number[1] == "") {
                    q->phone_number[1] == " ";

                }
                if (q->phone_number[2] == "") {
                    q->phone_number[2] == " ";

                }
                if (q->phone_number[3] == "") {
                    q->phone_number[3] == " ";

                }
                file_ << q->name << ',' << q->surname << ',' << q->address << ',' << q->e_mail[0] << "," << q->e_mail[1] << ',' << q->e_mail[2] << "," << q->e_mail[3] << "," << q->phone_number[0] << "," << q->phone_number[1] << "," << q->phone_number[2] << "," << q->phone_number[3] << endl;
                q = q->next;
            }
        }

        file_.close();
    }


    void show_index() {

        node* q = NULL;
        q = head;
        int k = 0;
        while (q != NULL)
        {
            k++;
            cout << k << "|" << q->name << " " << q->surname << endl;

            q = q->next;
        }



    }


    void del(int d_person) {
        int counterr = 1;
        struct node* prev = NULL;
        struct node* after = NULL;
        struct node* q = NULL;
        struct node* q_prev = NULL;
        int counter = 0;
        q = head;
        bool find = true;

        while (q != NULL) {

            counter++;
            q = q->next;
        }

        if (counter < d_person) {
            cout << "You wrote a number that is bigger than number your list has...\n";
            return;


        }
        q = head;

        while (1) {
            if (d_person == 1) {
                q = head;
                break;

            }

            if ((counterr + 1) == (d_person)) {
                q_prev = q;
                q = q->next;
                break;
            }
            if (q == NULL) {
                find = false;
                break;
            }
            q = q->next;
            counterr++;
        }

        if (!find) {
            cout << "There is no person you write" << endl;
        }

        if (find) {
            if (q == head) {
                if (q->next != NULL) {
                    q = head->next;

                    free(head);
                    head = q;
                }
                else if (q->next == NULL) {
                    free(head);
                    head = NULL;


                }


            }

            else if (q->next == NULL) {

                free(q);
                q = NULL;
                q_prev->next = NULL;
                tail = q_prev;
            }

            else {
                prev = q_prev;
                after = q->next;
                free(q);
                prev->next = after;
            }
            cout << "Person deleted.You can look your list \n";

        }
    }


};


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
    cout << "6:Write my list to text file(This will done automotically end of the program)" << endl;
    cout << "7:Add extra e_mail address" << endl;
    cout << "8:Add extra phone number" << endl;
    cout << "Q:Exit" << endl;

    cout << "Please select an option:";
    cin >> choose;
    return choose;

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


    linked_list a;

    a.take_text();
    bool sec = false;
    char ch = Option_show();
    bool sec2 = false;

    if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == 'Q' || ch == 'q') {


    }

    else {
        while (!sec2) {
            cout << "Wrong selection.Please again enter " << endl;
            ch = Option_show();
            if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == 'Q' || ch == 'q') {
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
            cout << endl;
            a.add_node(isim, soyisim, mail, telnum, adres);
            cout << "1:Main Scream Q:Exit:";

            cin >> secim;


            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
        }

        else if (ch == '2') {
            system("cls");

            int del_person;
            //linked_list::display(a.gethead());
            a.show_index();
            cout << "Enter index number you want to delete:" << endl;
            cin.ignore(256, '\n');
            cin >> del_person;

            a.del(del_person);

            cout << "1:Main Scream Q:Exit:";

            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
        }


        else if (ch == '3') {
            system("cls");

            string edit_personn;
            int i = 0;
            string new_stat;
            bool slc = false;
            cout << "Please enter name you want edit:";
            cin.ignore(256, '\n');
            getline(cin, edit_personn);
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

            a.edit_person(edit_personn, i, new_stat);


            cout << "Change okay.What do you want now?";

            cout << "1:Main Scream Q:Exit:";
            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
        }



        else if (ch == '4') {
            system("cls");


            linked_list::display(a.gethead());

            cout << "1:Main Scream Q:Exit:";
            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
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
                cout << "Enter a number you want to search:" << endl;
                cin.ignore(256, '\n');
                getline(cin, search);
            }
            a.search_person(search, option);

            cout << "1:Main Scream Q:Exit:";
            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
        }



        else if (ch == '6') {
            system("cls");


            a.write_text();

            cout << "1:Main Scream Q:Exit:" << endl;
            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }
        }


        else if (ch == 'Q' || ch == 'q') {

            cout << "GoodBye...";
            a.write_text();
            break;
        }

        else if (ch == '8') {
            system("cls");


            int ss;
            string new_e;
            char secim;
            a.show_index();
            cout << "Enter  index value you want to add phone number:";
            cin >> ss;
            cout << "Enter new phone number:";
            cin >> new_e;

            a.add_number(ss, new_e);
            cout << "1:Main Stream Q:Quit: ";

            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }

        }





        else if (ch == '7') {
            system("cls");


            int ss;
            string new_e;
            char secim;
            a.show_index();
            cout << "Enter  index value you want to add new mail:";
            cin >> ss;
            cout << "Enter new mail:";
            cin >> new_e;

            a.add_mail(ss, new_e);
            cout << "1:Main Stream Q:Quit: ";

            cin >> secim;
            if (secim == '1') {

                ch = Option_show();


            }

            else if (secim == 'Q' || secim == 'q') {

                ch = 'Q';

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
                        }
                        else {
                            ch = 'Q';
                        }
                    }
                }
            }

        }

        else {

            cout << "You did wrong selection.Please check again.";
            ch = Option_show();

        }
    }
    return 0;
}
