
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


using namespace std;
ofstream file_;

#include "MyHash.h"//K�t�phane header'� dahil edildi.
list::list() {
	/*�lk olarak bilgilerin tutulaca�� array i�erisindeki b�t�n karakterleri empty ile dolduruluyor.Bunun
	sebebi kullan�c� i�lem yapt�ktan sonra gerekli arrayin kullan�c�n�n girdi�i bilgiler do�rultusunda
	doldurulmas� ve geri kalanlar�n bo� oldu�unun anla��lmas� i�in.*/

	for (int i = 0;i < tableSize;i++) {

		HashTable[i] = new item;
		NumberTable[i] = new item2;
		HashTable[i]->name = "empty";
		HashTable[i]->surname = "empty";
		HashTable[i]->address = "empty";
		HashTable[i]->mail[0] = "empty";
		HashTable[i]->mail[1] = "empty";
		HashTable[i]->mail[2] = "empty";
		HashTable[i]->mail[3] = "empty";
		HashTable[i]->phone_number[0] = "empty";
		HashTable[i]->phone_number[1] = "empty";
		HashTable[i]->phone_number[2] = "empty";
		HashTable[i]->phone_number[3] = "empty";
		HashTable[i]->phone_number[0] = "empty";
		NumberTable[i]->num = "empty";
		NumberTable[i]->index = -1;

		HashTable[i]->next = NULL;
	}
}

int list::Hash(string key) {

	/*Bu k�s�mda key olarak kullan�c�n�n girdi�i isim de�eri tutuluyor. Gelen isim de�erinin ASCII kod kar��l���nda
	her harfin toplam� bulunuyor ve mod i�lemininde �ak��ma olmamas� i��n 17 asal say�s� ile her de�er �arp�l�yor.
	Daha sonra eleman say�s� olan 100 de�erine g�re mod bulunup return ile d�n�� yap�yor. Asl�nda burada yap�lan
	d�n�� de�eri hangi indiste i�lem yap�laca��n� belirtiyor.*/


	int hash = 0;//Key de�erlerinin toplam�n�n tutulaca�� de�er.
	int index;//Mod alma i�lemi esnas�nda kullan�lacak de�i�ken.
	for (int i = 0;i < key.length();i++) {

		hash += (hash + (int)key[i]) * 17;//B�t�n harfler s�ra ile toplanacak.
	}
	if (hash < 0) {
		hash = hash * -1;//Mod de�eri eksi d�nemez.��nk� indeks 0 dan ba�l�yor. Herhangi bir bug olu�up - gelirse +'ya d�nmesi gerekiyor.

	}
	index = hash % tableSize;
	return index;
}

void list::AddItemList(string name, string surname, string address, string mail, string phone) {
	/*Ki�i eleme i�lemlerinin yap�ld��� blok. Kullan�c�dan ki�i bilgileri al�n�yor ve bu fonksiyon �a�r�l�yor.
	Bu fonksiyonda ilk olarak key olan isim de�erinin modu al�narak hangi indise kay�t yap�laca�� belirleniyor.
	devam�nda kullan�c�n�n girdi�i ismin ald��� mod de�erinin array �zerinde dolu olup olmad��� kontrol ediliyor. E�er indis
	bo� ise direkt olarak o indise kay�t i�lemi yap�l�yor. Ama o indis dolu ise indis de�eri bir artt�r�l�yor ve bu kontrol
	empty olan kadar devam ediyor. Empty olan indis bulununca kay�t i�lemi o indise yap�l�yor.*/
	int index = Hash(name);//Mod de�eri

	if (HashTable[index]->name == "empty") {//E�er indis bo� ise atamay� buraya yap.
		HashTable[index]->name = name;
		HashTable[index]->surname = surname;
		HashTable[index]->address = address;
		HashTable[index]->mail[0] = mail;
		HashTable[index]->phone_number[0] = phone;


		int numb = Hash(HashTable[index]->phone_number[0]);
		while (NumberTable[numb]->num != "empty" && tableSize2 < 100) {
			numb++;
		}
		NumberTable[numb]->num = HashTable[index]->phone_number[0];
		NumberTable[numb]->index = index;
	}

	else {
		//item* Ptr = HashTable[index];
		item* n = new item;// Kullan�c�n�n girdi�i bilgiler n ad�nda bir item tipinde pointera kay�t ediliyor.
		n->name = name;
		n->surname = surname;
		n->address = address;

		n->mail[0] = mail;
		n->mail[1] = "empty";
		n->mail[2] = "empty";
		n->mail[3] = "empty";

		n->phone_number[0] = phone;
		n->phone_number[1] = "empty";
		n->phone_number[2] = "empty";
		n->phone_number[3] = "empty";


		n->next = NULL;
		while (HashTable[index]->name != "empty") {// �ndis bo� olana kadar artt�l�yor ve bo� bulununca d�ng� k�r�l�p o indise ekleme yap�l�yor.

			index++;
		}
		HashTable[index] = n;

		int numb = Hash(HashTable[index]->phone_number[0]);
		while (NumberTable[numb]->num != "empty" && tableSize2 < 100) {
			numb++;
		}
		NumberTable[numb]->num = HashTable[index]->phone_number[0];
		NumberTable[numb]->index = index;
		//Ptr->next = n;
	}
}


void list::AddItemListfromtext(string name, string surname, string address, string mail, string mail1, string
	mail2, string mail3, string phone, string phone1, string phone2, string phone3) {

	/*Bu fonksiyon ayn� yukar�daki ad fonksiyonu mant���nda �al���yor. Bunun yaz�l�� amac�, yaz�l�m�mda
	kullan�c�n�n ekstra mail ve telefon numaralar�n�n ba��ms�z olarak al�nmas�ndan kaynakl�. Programda kullan�c�
	istedi�i �ekilde extra numara ve mail ekliyor ama text i�lemleri i�in bu fonksiyona gerek duyuluyor.
	Text �zerinde yaz�l� olan verileri program�n a��l���nda i�eri aktarmam gerekiyor ve bu i�lemi yukar�daki fonksiyon
	ile yap�lam�yr.��nk� yukar�daki fonksiyon ekstra verileri parametre olarak alm�yor. Bu sebeple hepsini i�eren ve
	tex dosyas�ndan okuma yapma i�lemlerinde kullan�l�yor.*/

	//A��klamalar yukar�daki fonksiyon ile ayn� �ekilde.
	int index = Hash(name);

	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->surname = surname;
		HashTable[index]->address = address;
		HashTable[index]->mail[0] = mail;
		HashTable[index]->mail[1] = mail1;
		HashTable[index]->mail[2] = mail2;
		HashTable[index]->mail[3] = mail3;

		HashTable[index]->phone_number[0] = phone;
		HashTable[index]->phone_number[1] = phone1;
		HashTable[index]->phone_number[2] = phone2;
		HashTable[index]->phone_number[3] = phone3;
		int numb = Hash(HashTable[index]->phone_number[0]);
		while (NumberTable[numb]->num != "empty" && tableSize2 < 100) {
			numb++;
		}
		NumberTable[numb]->num = HashTable[index]->phone_number[0];
		NumberTable[numb]->index = index;


	}

	else {

		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->surname = surname;
		n->address = address;

		n->mail[0] = mail;
		n->mail[1] = mail1;
		n->mail[2] = mail2;
		n->mail[3] = mail3;

		n->phone_number[0] = phone;
		n->phone_number[1] = phone1;
		n->phone_number[2] = phone2;
		n->phone_number[3] = phone3;


		n->next = NULL;
		while (HashTable[index]->name != "empty") {

			index++;
		}
		HashTable[index] = n;
		int numb = Hash(HashTable[index]->phone_number[0]);
		while (NumberTable[numb]->num != "empty" && tableSize2 < 100) {
			numb++;
		}
		NumberTable[numb]->num = HashTable[index]->phone_number[0];
		NumberTable[numb]->index = index;
	}
}


void list::ShowList() {
	/*Kullan�c�n�n kay�t defterini g�r�nt�lemesi maksad� ile yaz�lan fonksiyon. Array eleman�ar� 0' dan ba�layarak
	array uzunlu�una kadar gidiyor ve her bir indis empty olmad��� s�redce b�t�n veriler ekrana yaz�l�yor.
	E�er kullan�c�, ki�i i�in ekstra bilgiler girmediyse o bilgiler bo�tan yere ekrana empty olarak yazd�r�lm�yor
	e�er de�er varsa yazd�r�l�yor.*/
	int number;

	for (int i = 0;i < tableSize;i++) {
		if (HashTable[i]->name != "empty") {
			//number = numberOfItemsIndex(i);
			cout << "*******************************" << endl;
			cout << "Name:" << HashTable[i]->name << endl;
			cout << "Surname:" << HashTable[i]->surname << endl;
			cout << "Address:" << HashTable[i]->address << endl;
			cout << "Mail:" << HashTable[i]->mail[0];

			//E�er ekstra de�erler varsa yazd�r, yoksa bo� yere empty yazma.
			if (HashTable[i]->mail[1] != "empty") {
				cout << " " << HashTable[i]->mail[1];
			}
			if (HashTable[i]->mail[2] != "empty") {
				cout << " " << HashTable[i]->mail[2];
			}
			if (HashTable[i]->mail[3] != "empty") {
				cout << " " << HashTable[i]->mail[3];
			}
			cout << endl;
			cout << "Phone:" << HashTable[i]->phone_number[0];
			if (HashTable[i]->phone_number[1] != "empty") {

				cout << " " << HashTable[i]->phone_number[1];
			}
			if (HashTable[i]->phone_number[2] != "empty") {

				cout << " " << HashTable[i]->phone_number[2];
			}
			if (HashTable[i]->phone_number[3] != "empty") {

				cout << " " << HashTable[i]->phone_number[3];
			}
			cout << endl;



			cout << "********************************" << endl;
		}

	}
}
void list::FindPerson(string word, char select) {

	//Arama i�lemi i�in yaz�lan fonksiyon. Kullan�c� hem isme hem de numaraya g�re arama yapabiliyor. Burada ki p�f nokta
	//kullan�c� ismin tamam�n� girmeyebilir. O zaman bizim mod de�erimiz bozulabilir ve ismin oldu�u moddan ileriye d�n�k
	//bir mod de�eri d�nebilir. Bunun �nlemi ise �u �ekilde al�nd�. Kullan�c�n�n girdi�i ismin modu al�n�yor ve o indisten
	//arama ba�lat�l�yor. E�er arama bulunamad�ysa indis 0 a al�n�yor ve bulunan indise kadar olan k�s�mda da arama i�lemi
	//ger�ekle�tiriliyor.Bu sayede arama i�lemi ile h�z sa�lanm�� oluyor.Bu fonksiyonda selext de�i�keni isme g�re mi yoksa
	//numaraya g�re mi arama yap�laca��n� belirtiyor.


	int index = Hash(word);//�ndis-Mod
	int prev_index = index - 1;//Ba�a d�n�ld���nde d�ng�n�n biti�inin kontrol� i�in index'in bir eksi�i haf�zada tutuluyor.
	item* Ptr = HashTable[index];
	bool isfound = false;//Bulunma i�lemi i�in do�rulama de�i�keni

	if (select == '1') {
		//�sme g�re arama i�lemi
		while (index < tableSize && index != prev_index) {

			if ((HashTable[index]->name).find(word) != string::npos) {
				isfound = true;
				cout << "*******************************" << endl;
				cout << "Name:" << HashTable[index]->name << endl;
				cout << "Surname:" << HashTable[index]->surname << endl;
				cout << "Address:" << HashTable[index]->address << endl;
				cout << "Mail:" << HashTable[index]->mail[0] << " ";
				if (HashTable[index]->mail[1] != "empty") {
					cout << HashTable[index]->mail[1] << " ";
				}
				if (HashTable[index]->mail[2] != "empty") {
					cout << HashTable[index]->mail[2] << " ";
				}if (HashTable[index]->mail[3] != "empty") {
					cout << HashTable[index]->mail[3] << " ";
				}
				cout << endl;
				cout << "Phone:" << HashTable[index]->phone_number[0] << " ";
				if (HashTable[index]->phone_number[1] != "empty") {
					cout << HashTable[index]->phone_number[1] << " ";

				}
				if (HashTable[index]->phone_number[2] != "empty") {
					cout << HashTable[index]->phone_number[2] << " ";

				}if (HashTable[index]->phone_number[3] != "empty") {
					cout << HashTable[index]->phone_number[3] << " ";

				}
				cout << endl;
				cout << "********************************" << endl;

			}
			index++;
			if (index == tableSize) {
				index = 0;
			}

		}
		//E�er arama sonucunda bulma olmazsa kullan�c�ya tekrar arama yapma imkan� sunuluyor.
		if (!isfound) {
			int again;
			cout << "There is no person which name is you write...\n";
			cout << "Do you want try again?\n1-YES/2-NO:";
			cin >> again;
			if (again == 1) {
				cout << "Please enter name:";
				string again_name;
				cin.ignore(256, '\n');
				getline(cin, again_name);
				FindPerson(again_name, 1);


			}

		}

	}

	else if (select == '2') {
		int i = Hash(word);
		item2* ptr = new item2;
		ptr = NumberTable[i];
		while (i < tableSize) {

			if ((ptr->num).find(word) != string::npos)

			{
				isfound = true;
				cout << "*******************************" << endl;
				cout << "Name:" << HashTable[ptr->index]->name << endl;
				cout << "Surname:" << HashTable[ptr->index]->surname << endl;
				cout << "Address:" << HashTable[ptr->index]->address << endl;
				cout << "Mail:" << HashTable[ptr->index]->mail[0] << endl;
				cout << "Phone:" << HashTable[ptr->index]->phone_number[0] << endl;
				cout << "********************************" << endl;

			}
			i++;
			ptr = NumberTable[i];

		}


	}
	if (!isfound) {
		cout << "There is no people which number is you write...\n";
	}
}


void list::editPerson(string name, string state, int i) {

	/*Bu fonksiyon ile kullan�c� ekli olan ki�ilerin bilgilerinde d�zenleme i�lemi yapabiliyor. �lk olarak d�zenleme
	yapmak istedi�i ki�inin ismini giriyor ve bu isim liste i�eriside aran�yor. Buradaki �nemli nokta, kullan�c�n�n
	girdi�i ki�i, rehberde kay�tl� olan tek ayn� isdim olmayabilir. Bu durumda b�t�n bulunan isimler ekrana yazd�r�l�yor
	ve kullan�c�dan o isme sahip ka� ki�i oldu�u g�steriliyor ve hangisini editlemek istiyorsun �eklinde bir soru
	y�neltiliyor. Bu durumda kullan�c� de�i�tirmek istedi�i ki�inin ekrandaki numaras�n� veriyor. Di�er bir p�f nokta
	ise kullan�c�n�n, programda key olarak belirtti�im isim de�i�kenini editlemesi. E�er b�yle bir durum olursa
	de�i�tirme i�lemi sonras�nda arama, silme ve ya di�er fonksiyonlarda de�i�iklik olabilir ��nk� ismin modu de�i�iyor.
	Bu durumda isim de�i�keni de�i�tirilmek istendi�i zaman o indisin b�t�n bilgileri al�n�yor ve yukar�da anlat�lan
	add personfrom text fonksiyonu kullan�l�yor. Bu sayede ekstra bilgiler kaybedilmeden yeni ki�i ekleme yap�l�yor ve o indis ser
	best b�rak�l�yor.

	*/
	int index = Hash(name);// Mod
	item* Ptr = HashTable[index];
	int whois[5];//Ayn� isme sahip 5 ki�i olma durumu.Daha da artt�r�labilir
	bool isfound = false;//Bulma sorgusu i�in boolean bir de�er
	int count = 0;//Ayn� isme sahip birden fazla ki�i olursa whois de�i�keninde index de�erinin tutulmas� i�in 

	while (index < tableSize) {

		if ((HashTable[index]->name).find(name) != string::npos) {
			isfound = true;
			whois[count] = index;//0. ki�i ve index de�erinden ba�layarak count artt�r�l�yor, e�er ayn� isme sahip bir ba�ka ki�ide varsa 1. de�i�kene at�l�yor.B�yle b�yle 5 tane olabilir.
			count++;
			cout << count << "||" << HashTable[index]->name << " " << HashTable[index]->surname << ",Address:" << HashTable[index]->address << "Phone number:" << HashTable[index]->phone_number[0] << " ";
			if (HashTable[index]->phone_number[1] != "empty") {
				cout << HashTable[index]->phone_number[1] << " ";
			}
			if (HashTable[index]->phone_number[2] != "empty") {
				cout << HashTable[index]->phone_number[2] << " ";
			}if (HashTable[index]->phone_number[3] != "empty") {
				cout << HashTable[index]->phone_number[3] << " ";
			}


			cout << "Mail:" << HashTable[index]->mail[0] << "  ";

			if (HashTable[index]->mail[1] != "empty") {
				cout << "Mail:" << HashTable[index]->mail[1] << "  ";


			}
			if (HashTable[index]->mail[2] != "empty") {
				cout << "Mail:" << HashTable[index]->mail[2] << "  ";


			}
			if (HashTable[index]->mail[3] != "empty") {
				cout << "Mail:" << HashTable[index]->mail[3] << "  ";


			}
			cout << endl;


		}
		index++;
	}

	/*Bulma i�leminin sorgular� ger�ekle�tiriliyor. E�er birdeb fazla ki�i varsa kullan�c�ya se�im hakk� veriliyor*/
	int select = 0;

	if (count == 0) {
		cout << "There is no people you write...\n";
		isfound = false;

	}
	else if (count == 1) {

		select = 1;
	}
	else if (count > 1) {
		cout << "There is " << count << " people.Which one do you want edit?:";
		//1'den fazla ayn� isme sahip ki�i varsa indexlerin bulundu�u whois arrayi i�in index al�nma i�lemi
		//ge�ekle�tiriliyor.

		cin >> select;
		while (select < 1 || select > count) {

			cout << "Wrong selection.Please again:";
			cin >> select;

		}

	}
	if (isfound) {
		index = whois[(select - 1)];
		string n_name, n_surname, n_address, n_mail, n_mail1, n_mail2, n_mail3, n_phone, n_phone1, n_phone2, n_phone3;

		//state de�ilkeni yeni durumu, i de�i�keni ise de�i�tirilmek istenen �zelli�i temsil ediyor.
		if (i == 1) {
			//E�er isim de�i�keni de�i�tirilmek istenirse yukar�da anlatt���m algoritma devreye girecek ve yeni bir
	//ki�i ekleniyormu� gibi d���n�l�p o indexe ki�i eklenecek. 

			n_name = state;
			n_surname = HashTable[index]->surname;
			n_address = HashTable[index]->address;
			n_mail = HashTable[index]->mail[0];
			n_mail1 = HashTable[index]->mail[1];
			n_mail2 = HashTable[index]->mail[2];
			n_mail3 = HashTable[index]->mail[3];
			n_phone = HashTable[index]->phone_number[0];
			n_phone1 = HashTable[index]->phone_number[1];
			n_phone2 = HashTable[index]->phone_number[2];
			n_phone3 = HashTable[index]->phone_number[3];
			HashTable[index]->name = "empty";
			HashTable[index]->surname = "empty";
			HashTable[index]->address = "empty";
			HashTable[index]->mail[0] = "empty";
			HashTable[index]->mail[1] = "empty";
			HashTable[index]->mail[2] = "empty";
			HashTable[index]->mail[3] = "empty";
			HashTable[index]->phone_number[0] = "empty";
			HashTable[index]->phone_number[1] = "empty";
			HashTable[index]->phone_number[2] = "empty";
			HashTable[index]->phone_number[3] = "empty";
			int ind = Hash(n_phone);
			while (NumberTable[ind]->num != n_phone) { ind++; }
			NumberTable[ind]->num = "empty";
			NumberTable[ind]->index = -1;



			AddItemListfromtext(n_name, n_surname, n_address, n_mail, n_mail1, n_mail2, n_mail3, n_phone, n_phone1, n_phone2, n_phone3);

		}
		else if (i == 2) {
			HashTable[index]->surname = state;

		}
		else if (i == 3) {
			HashTable[index]->address = state;

		}
		else if (i == 4) {
			//E�er varsaekstra numara ve mail de�i�kenlerinden hangisinin d�zenlenmek istendi�i kullan�c�ya soruluyor.

			if (HashTable[index]->mail[1] == "empty" && HashTable[index]->mail[2] == "empty" && HashTable[index]->mail[3] == "empty")
			{
				HashTable[index]->mail[0] = state;
			}

			else if (HashTable[index]->mail[1] != "empty" && HashTable[index]->mail[2] == "empty" && HashTable[index]->mail[3] == "empty") {
				cout << "Which one do you want edit?\n1:Mail-1\n2:Mail-2:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					HashTable[index]->mail[0] = state;
				}
				else if (choose == 2) {

					HashTable[index]->mail[1] = state;

				}
			}


			else if (HashTable[index]->mail[1] != "empty" && HashTable[index]->mail[2] != "empty" && HashTable[index]->mail[3] == "empty") {
				cout << "Which one do you want edit?\n1:Mail-1\n2:Mail-2:\n3:Mail-3:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					HashTable[index]->mail[0] = state;
				}
				else if (choose == 2) {

					HashTable[index]->mail[1] = state;

				}
				else if (choose == 3) {

					HashTable[index]->mail[2] = state;

				}
			}

			else if (HashTable[index]->mail[1] != "empty" && HashTable[index]->mail[2] != "empty" && HashTable[index]->mail[3] != "empty") {
				cout << "Which one do you want edit?\n1:Mail-1\n2:Mail-2\n3:Mail-3\n4:Mail-4:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					HashTable[index]->mail[0] = state;

				}
				else if (choose == 2) {

					HashTable[index]->mail[1] = state;

				}
				else if (choose == 3) {

					HashTable[index]->mail[2] = state;

				}
				else if (choose == 4) {

					HashTable[index]->mail[3] = state;

				}
			}
		}

		else if (i == 5) {
			if (HashTable[index]->phone_number[1] == "empty" && HashTable[index]->phone_number[2] == "empty" && HashTable[index]->phone_number[3] == "empty")
			{
				string old_phone = HashTable[index]->phone_number[0];
				HashTable[index]->phone_number[0] = state;
				int ind = Hash(old_phone);
				int ind2 = Hash(state);

				while ((NumberTable[ind]->num) != old_phone) {
					ind++;
				}
				NumberTable[ind]->num = "empty";
				NumberTable[ind]->index = -1;

				while (NumberTable[ind2]->num != "empty") {
					ind2++;

				}
				NumberTable[ind2]->num = state;
				NumberTable[ind2]->index = index;


			}

			else if (HashTable[index]->phone_number[1] != "empty" && HashTable[index]->phone_number[2] == "empty" && HashTable[index]->phone_number[3] == "empty") {
				cout << "Which one do you want edit?\n1:Number-1\n2:Number-2:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					string old_phone = HashTable[index]->phone_number[0];
					HashTable[index]->phone_number[0] = state;
					int ind = Hash(old_phone);
					int ind2 = Hash(state);

					while ((NumberTable[ind]->num) != old_phone) {
						ind++;
					}
					NumberTable[ind]->num = "empty";
					NumberTable[ind]->index = -1;

					while (NumberTable[ind2]->num != "empty") {
						ind2++;

					}
					NumberTable[ind2]->num = state;
					NumberTable[ind2]->index = index;

				}
				else if (choose == 2) {

					HashTable[index]->phone_number[1] = state;

				}
			}


			else if (HashTable[index]->phone_number[1] != "empty" && HashTable[index]->phone_number[2] != "empty" && HashTable[index]->phone_number[3] == "empty") {
				cout << "Which one do you want edit?\n1:Number-1\n2:Number-2:\n3:Number-3:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					string old_phone = HashTable[index]->phone_number[0];
					HashTable[index]->phone_number[0] = state;
					int ind = Hash(old_phone);
					int ind2 = Hash(state);

					while ((NumberTable[ind]->num) != old_phone) {
						ind++;
					}
					NumberTable[ind]->num = "empty";
					NumberTable[ind]->index = -1;

					while (NumberTable[ind2]->num != "empty") {
						ind2++;

					}
					NumberTable[ind2]->num = state;
					NumberTable[ind2]->index = index;
				}
				else if (choose == 2) {

					HashTable[index]->phone_number[1] = state;

				}
				else if (choose == 3) {

					HashTable[index]->phone_number[2] = state;

				}
			}

			else if (HashTable[index]->phone_number[1] != "empty" && HashTable[index]->phone_number[2] != "empty" && HashTable[index]->phone_number[3] != "empty") {
				cout << "Which one do you want edit?\n1:Number-1\n2:Number-2\n3:Number-3\n4:Number-4:";
				int choose;
				cin >> choose;
				if (choose == 1) {
					string old_phone = HashTable[index]->phone_number[0];
					HashTable[index]->phone_number[0] = state;
					int ind = Hash(old_phone);
					int ind2 = Hash(state);

					while ((NumberTable[ind]->num) != old_phone) {
						ind++;
					}
					NumberTable[ind]->num = "empty";
					NumberTable[ind]->index = -1;

					while (NumberTable[ind2]->num != "empty") {
						ind2++;

					}
					NumberTable[ind2]->num = state;
					NumberTable[ind2]->index = index;
				}
				else if (choose == 2) {

					HashTable[index]->phone_number[1] = state;

				}
				else if (choose == 3) {

					HashTable[index]->phone_number[2] = state;

				}
				else if (choose == 4) {

					HashTable[index]->phone_number[3] = state;

				}
			}

		}
	}


}

void list::addExtra(string name, string word, int option) {

	//Kullan�c� bir ki�iye ekstra numara ve ya mail eklemek isterse bu fonksiyon yard�m� ile i�lem ger�ekle�tiriliyor.
	//Kullan�c� eklemek istedi�i ki�inin ismini se�iyor ve ilk olarak girilen isim aran�yor. E�er isimden 1'den fazla var 
	//ise bir �nceki uygulamada oldu�u gibi hangisine ekleme yapmak istedi�i i�in ekstra bir sorgu ger�ekle�tiriliyor.
	//Kullan�c� se�imini yapt�ktan sonra eklemek istedi�i mail ve ya numara de�i�kenini sisteme giriyor. bu sayede istedi�i
	//ki�iye numara ve ya mail eklemesi geer�ekle�tiriliyor. Buradaki option parametresi ile kullan�c�ya sorulmadan
	//main i�erisinde gerekli ba�l�klarda yaz�l�mc� taraf�ndan verilmi�tir. bu sayede ayr� ayr� fonksiyon yazmak yerine
	//tek fonksiyonda iki i�lem yerine getirilmi�tir. Eklemek istenen de�erler i�in ekstra bilgilerin tutuldu�u
	//de�i�kenlerin doluluk durumu g�zleniyor ve bulunan ilk bo�ta elemana ekleme yap�l�yor.

	int index = Hash(name);
	item* Ptr = HashTable[index];
	bool isfound = false;
	int count = 0;

	int whois[5];
	while (index < tableSize) {

		if ((HashTable[index]->name) == name) {
			isfound = true;
			whois[count] = index;
			count++;
			cout << count << "||" << HashTable[index]->name << " " << HashTable[index]->surname << " " << HashTable[index]->address << "," << HashTable[index]->phone_number[0] << "," << HashTable[index]->mail[0] << " \n";

		}
		index++;
	}
	int select = 0;

	if (count == 0) {
		cout << "There is no people you write...\n";
		isfound = false;

	}
	else if (count == 1) {

		select = 1;

	}

	else if (count > 1) {
		cout << "There is " << count << " people.Which one do you want add ?:";
		cin >> select;
		while (select < 1 || select > count) {

			cout << "Wrong selection.Please again:";
			cin >> select;

		}
	}

	if (isfound) {
		index = whois[select - 1];
		Ptr = HashTable[index];
	}

	if (isfound) {
		if (option == 1) {
			if (Ptr->phone_number[1] == "empty") {
				Ptr->phone_number[1] = word;

			}

			else if (Ptr->phone_number[2] == "empty") {
				Ptr->phone_number[2] = word;
			}
			else if (Ptr->phone_number[3] == "empty") {
				Ptr->phone_number[3] = word;
			}
			else
				cout << "Your limit is full.You can not add new number\n";

		}
		else if (option == 2) {

			if (Ptr->mail[1] == "empty") {
				Ptr->mail[1] = word;

			}

			else if (Ptr->mail[2] == "empty") {
				Ptr->mail[2] = word;
			}
			else if (Ptr->mail[3] == "empty") {
				Ptr->mail[3] = word;
			}
			else
				cout << "Your limit is full.You can not add new number\n";

		}

	}
}

void list::writeTex() {
	//Olu�turulan liste, program�n tekrar �al��t�r�lmas� durumunda haf�zaya al�nabilmek i�in program�n sonunda kay�t
	//i�lemine tabii tutuluyor.
	int number;
	file_.open("MyList.txt");
	if (file_.is_open()) {

		for (int i = 0;i < tableSize;i++) {
			if (HashTable[i]->name != "empty") {
				file_ << HashTable[i]->name << "," << HashTable[i]->surname << "," << HashTable[i]->address << "," << HashTable[i]->mail[0] << "," << HashTable[i]->mail[1] << "," << HashTable[i]->mail[2] << "," << HashTable[i]->mail[3] << "," << HashTable[i]->phone_number[0] << "," << HashTable[i]->phone_number[1] << "," << HashTable[i]->phone_number[2] << "," << HashTable[i]->phone_number[3] << "," << endl;



			}
		}

	}
	file_.close();

}

void list::tokenize(std::string const& str, const char delim,
	std::vector<std::string>& out)
{
	//Texten veri okumak i�in yaz�lan bir fonksiyon. Texin b�t�n bir sat�r� okunuyor ve kullan�c�n�n istedi�i karaketere
	//g�re string ler par�alan�yor. Bu sayede her bir ki�inin isim, soyisim ,numara gibi de�i�kenleri birbirine kar��madan
	//tekrar programa �ekiliyor.

	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

void list::takeFromtext() {
	//Program tekrar a��ld���nda bir �nceki ki�ilerin programa dahi ledilmesini sa�layan fonksiyon. Bu fonksiyon ile kaydedilen
	//text i�erisindeki veriler s�ras�yla sisteme �ekiliyor ve addfrom text de�i�keni sayesinde tekrardan i�e aktar�m sa�lan�yor.
	//Text �zerine veriler ',' ler ile yar�larak yaz�l�yor ve okunma i�lemi s�ras�nda bir yukar�daki fonksiyon sayesinde
	//herbir sat�r virg�ller yard�m�yla ayr�l�yor ve bir array i�erisinde tutuluyor ve ard�ndan her bir �zellik sisteme aktar�l�yor.
	int index = 0;
	string line;//sat�r sat�r okuma i�lemi i�in tan�mlanan de�i�ken
	string info[11];//Totalde 11 deet bilgi bulunuyor. Herbirini i�erisinde tutmak i�in olu�turulan array
	ifstream myfile("MyList.txt");//Dosyan�n ismi

	if (myfile.is_open())
	{
		while (myfile.good())
		{

			int countt = 0;//Sistemin ba��nda s�f�rlan�p 10'a kadar gidecek olan index tutucu de�i�ken
			const char delim = ',';//virg�l ile ayr�lma i�in kullan�lan de�i�ken
			getline(myfile, line);

			std::vector<std::string> out;
			tokenize(line, delim, out);
			//Virg�ller ile ayr�lma yap�l�p ki�ilerin eklend�i k�s�m. Her bir sat�r i�in 11 kere d�necek ve herbir eleman� arraye atayacak.
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
				}

				else if (countt == 10) {

					int index = Hash(info[0]);
					string name = info[0];
					string surname = info[1];
					string address = info[2];
					string mail = info[3];
					string mail1 = info[4];
					string mail2 = info[5];
					string mail3 = info[6];

					string phone = info[7];
					string phone1 = info[8];
					string phone2 = info[9];
					string phone3 = line;
					AddItemListfromtext(name, surname, address, mail, mail1, mail2, mail3, phone, phone1, phone2, phone3);
				}



				countt++;
			}
		}


	}
}


void list::deletePerson(string name) {

	//Ki�i silme i�in tan�mlanan fonksiyon. Fonksiyon, yine silinmek istenen ki�ini ismini kullan�c�ya soruyor ve
	//ayn� isme aship ki�ilerin kontrol� sa�lan�yor. Bunun devam�nda o isme aship 1'den fazla ki�i varsa hangisinin 
	//silinece�i kullan�c�ya soruluyor. Daha sonra o index'te bulunan veriler 'empty' ile dolduruluyor.
	int index = Hash(name);
	int prev_index = index - 1;
	item* delPtr;
	item* p1;
	item* p2;
	int count = 0;
	bool isfound = false;
	int whois[5];
	while (index < tableSize && index != prev_index) {

		if ((HashTable[index]->name).find(name) != string::npos) {
			isfound = true;
			whois[count] = index;
			count++;
			cout << count << "||" << HashTable[index]->name << " " << HashTable[index]->surname << " " << HashTable[index]->address << "," << HashTable[index]->phone_number[0] << "," << HashTable[index]->mail[0] << " \n";

		}
		index++;
		if (index == 100) {
			index = 0;

		}

	}

	int select = 0;

	if (count == 0) {
		cout << "There is no people you write...\n";
		isfound = false;

	}
	else if (count == 1) {

		select = 1;
	}

	else if (count > 1) {
		cout << "There is " << count << " people.Which one do you want delete?:";
		cin >> select;
		while (select < 1 || select > count) {

			cout << "Wrong selection.Please again:";
			cin >> select;

		}
	}

	if (isfound) {
		index = whois[select - 1];

		int num_ind = Hash(HashTable[index]->phone_number[0]);
		while (NumberTable[num_ind]->num != HashTable[index]->phone_number[0]) {
			num_ind++;
		}
		NumberTable[num_ind]->num = "empty";
		NumberTable[num_ind]->index = -1;


		HashTable[index]->name = "empty";
		HashTable[index]->surname = "empty";
		HashTable[index]->address = "empty";

		HashTable[index]->mail[0] = "empty";
		HashTable[index]->mail[1] = "empty";
		HashTable[index]->mail[2] = "empty";
		HashTable[index]->mail[3] = "empty";

		HashTable[index]->phone_number[0] = "empty";
		HashTable[index]->phone_number[1] = "empty";
		HashTable[index]->phone_number[2] = "empty";
		HashTable[index]->phone_number[3] = "empty";

	}

}





