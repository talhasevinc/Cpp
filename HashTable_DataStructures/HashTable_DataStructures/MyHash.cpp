
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


using namespace std;
ofstream file_;

#include "MyHash.h"//Kütüphane header'ý dahil edildi.
list::list() {
	/*Ýlk olarak bilgilerin tutulacaðý array içerisindeki bütün karakterleri empty ile dolduruluyor.Bunun
	sebebi kullanýcý iþlem yaptýktan sonra gerekli arrayin kullanýcýnýn girdiði bilgiler doðrultusunda
	doldurulmasý ve geri kalanlarýn boþ olduðunun anlaþýlmasý için.*/

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

	/*Bu kýsýmda key olarak kullanýcýnýn girdiði isim deðeri tutuluyor. Gelen isim deðerinin ASCII kod karþýlýðýnda
	her harfin toplamý bulunuyor ve mod iþlemininde çakýþma olmamasý içþn 17 asal sayýsý ile her deðer çarpýlýyor.
	Daha sonra eleman sayýsý olan 100 deðerine göre mod bulunup return ile dönüþ yapýyor. Aslýnda burada yapýlan
	dönüþ deðeri hangi indiste iþlem yapýlacaðýný belirtiyor.*/


	int hash = 0;//Key deðerlerinin toplamýnýn tutulacaðý deðer.
	int index;//Mod alma iþlemi esnasýnda kullanýlacak deðiþken.
	for (int i = 0;i < key.length();i++) {

		hash += (hash + (int)key[i]) * 17;//Bütün harfler sýra ile toplanacak.
	}
	if (hash < 0) {
		hash = hash * -1;//Mod deðeri eksi dönemez.Çünkü indeks 0 dan baþlýyor. Herhangi bir bug oluþup - gelirse +'ya dönmesi gerekiyor.

	}
	index = hash % tableSize;
	return index;
}

void list::AddItemList(string name, string surname, string address, string mail, string phone) {
	/*Kiþi eleme iþlemlerinin yapýldýðý blok. Kullanýcýdan kiþi bilgileri alýnýyor ve bu fonksiyon çaðrýlýyor.
	Bu fonksiyonda ilk olarak key olan isim deðerinin modu alýnarak hangi indise kayýt yapýlacaðý belirleniyor.
	devamýnda kullanýcýnýn girdiði ismin aldýðý mod deðerinin array üzerinde dolu olup olmadýðý kontrol ediliyor. Eðer indis
	boþ ise direkt olarak o indise kayýt iþlemi yapýlýyor. Ama o indis dolu ise indis deðeri bir arttýrýlýyor ve bu kontrol
	empty olan kadar devam ediyor. Empty olan indis bulununca kayýt iþlemi o indise yapýlýyor.*/
	int index = Hash(name);//Mod deðeri

	if (HashTable[index]->name == "empty") {//Eðer indis boþ ise atamayý buraya yap.
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
		item* n = new item;// Kullanýcýnýn girdiði bilgiler n adýnda bir item tipinde pointera kayýt ediliyor.
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
		while (HashTable[index]->name != "empty") {// Ýndis boþ olana kadar arttýlýyor ve boþ bulununca döngü kýrýlýp o indise ekleme yapýlýyor.

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

	/*Bu fonksiyon ayný yukarýdaki ad fonksiyonu mantýðýnda çalýþýyor. Bunun yazýlýþ amacý, yazýlýmýmda
	kullanýcýnýn ekstra mail ve telefon numaralarýnýn baðýmsýz olarak alýnmasýndan kaynaklý. Programda kullanýcý
	istediði þekilde extra numara ve mail ekliyor ama text iþlemleri için bu fonksiyona gerek duyuluyor.
	Text üzerinde yazýlý olan verileri programýn açýlýþýnda içeri aktarmam gerekiyor ve bu iþlemi yukarýdaki fonksiyon
	ile yapýlamýyr.Çünkü yukarýdaki fonksiyon ekstra verileri parametre olarak almýyor. Bu sebeple hepsini içeren ve
	tex dosyasýndan okuma yapma iþlemlerinde kullanýlýyor.*/

	//Açýklamalar yukarýdaki fonksiyon ile ayný þekilde.
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
	/*Kullanýcýnýn kayýt defterini görüntülemesi maksadý ile yazýlan fonksiyon. Array elemanþarý 0' dan baþlayarak
	array uzunluðuna kadar gidiyor ve her bir indis empty olmadýðý süredce bütün veriler ekrana yazýlýyor.
	Eðer kullanýcý, kiþi için ekstra bilgiler girmediyse o bilgiler boþtan yere ekrana empty olarak yazdýrýlmýyor
	eðer deðer varsa yazdýrýlýyor.*/
	int number;

	for (int i = 0;i < tableSize;i++) {
		if (HashTable[i]->name != "empty") {
			//number = numberOfItemsIndex(i);
			cout << "*******************************" << endl;
			cout << "Name:" << HashTable[i]->name << endl;
			cout << "Surname:" << HashTable[i]->surname << endl;
			cout << "Address:" << HashTable[i]->address << endl;
			cout << "Mail:" << HashTable[i]->mail[0];

			//Eðer ekstra deðerler varsa yazdýr, yoksa boþ yere empty yazma.
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

	//Arama iþlemi için yazýlan fonksiyon. Kullanýcý hem isme hem de numaraya göre arama yapabiliyor. Burada ki püf nokta
	//kullanýcý ismin tamamýný girmeyebilir. O zaman bizim mod deðerimiz bozulabilir ve ismin olduðu moddan ileriye dönük
	//bir mod deðeri dönebilir. Bunun önlemi ise þu þekilde alýndý. Kullanýcýnýn girdiði ismin modu alýnýyor ve o indisten
	//arama baþlatýlýyor. Eðer arama bulunamadýysa indis 0 a alýnýyor ve bulunan indise kadar olan kýsýmda da arama iþlemi
	//gerçekleþtiriliyor.Bu sayede arama iþlemi ile hýz saðlanmýþ oluyor.Bu fonksiyonda selext deðiþkeni isme göre mi yoksa
	//numaraya göre mi arama yapýlacaðýný belirtiyor.


	int index = Hash(word);//Ýndis-Mod
	int prev_index = index - 1;//Baþa dönüldüðünde döngünün bitiþinin kontrolü için index'in bir eksiði hafýzada tutuluyor.
	item* Ptr = HashTable[index];
	bool isfound = false;//Bulunma iþlemi için doðrulama deðiþkeni

	if (select == '1') {
		//Ýsme göre arama iþlemi
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
		//Eðer arama sonucunda bulma olmazsa kullanýcýya tekrar arama yapma imkaný sunuluyor.
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

	/*Bu fonksiyon ile kullanýcý ekli olan kiþilerin bilgilerinde düzenleme iþlemi yapabiliyor. Ýlk olarak düzenleme
	yapmak istediði kiþinin ismini giriyor ve bu isim liste içeriside aranýyor. Buradaki önemli nokta, kullanýcýnýn
	girdiði kiþi, rehberde kayýtlý olan tek ayný isdim olmayabilir. Bu durumda bütün bulunan isimler ekrana yazdýrýlýyor
	ve kullanýcýdan o isme sahip kaç kiþi olduðu gösteriliyor ve hangisini editlemek istiyorsun þeklinde bir soru
	yöneltiliyor. Bu durumda kullanýcý deðiþtirmek istediði kiþinin ekrandaki numarasýný veriyor. Diðer bir püf nokta
	ise kullanýcýnýn, programda key olarak belirttiðim isim deðiþkenini editlemesi. Eðer böyle bir durum olursa
	deðiþtirme iþlemi sonrasýnda arama, silme ve ya diðer fonksiyonlarda deðiþiklik olabilir çünkü ismin modu deðiþiyor.
	Bu durumda isim deðiþkeni deðiþtirilmek istendiði zaman o indisin bütün bilgileri alýnýyor ve yukarýda anlatýlan
	add personfrom text fonksiyonu kullanýlýyor. Bu sayede ekstra bilgiler kaybedilmeden yeni kiþi ekleme yapýlýyor ve o indis ser
	best býrakýlýyor.

	*/
	int index = Hash(name);// Mod
	item* Ptr = HashTable[index];
	int whois[5];//Ayný isme sahip 5 kiþi olma durumu.Daha da arttýrýlabilir
	bool isfound = false;//Bulma sorgusu için boolean bir deðer
	int count = 0;//Ayný isme sahip birden fazla kiþi olursa whois deðiþkeninde index deðerinin tutulmasý için 

	while (index < tableSize) {

		if ((HashTable[index]->name).find(name) != string::npos) {
			isfound = true;
			whois[count] = index;//0. kiþi ve index deðerinden baþlayarak count arttýrýlýyor, eðer ayný isme sahip bir baþka kiþide varsa 1. deðiþkene atýlýyor.Böyle böyle 5 tane olabilir.
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

	/*Bulma iþleminin sorgularý gerçekleþtiriliyor. Eðer birdeb fazla kiþi varsa kullanýcýya seçim hakký veriliyor*/
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
		//1'den fazla ayný isme sahip kiþi varsa indexlerin bulunduðu whois arrayi için index alýnma iþlemi
		//geçekleþtiriliyor.

		cin >> select;
		while (select < 1 || select > count) {

			cout << "Wrong selection.Please again:";
			cin >> select;

		}

	}
	if (isfound) {
		index = whois[(select - 1)];
		string n_name, n_surname, n_address, n_mail, n_mail1, n_mail2, n_mail3, n_phone, n_phone1, n_phone2, n_phone3;

		//state deðilkeni yeni durumu, i deðiþkeni ise deðiþtirilmek istenen özelliði temsil ediyor.
		if (i == 1) {
			//Eðer isim deðiþkeni deðiþtirilmek istenirse yukarýda anlattýðým algoritma devreye girecek ve yeni bir
	//kiþi ekleniyormuþ gibi düþünülüp o indexe kiþi eklenecek. 

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
			//Eðer varsaekstra numara ve mail deðiþkenlerinden hangisinin düzenlenmek istendiði kullanýcýya soruluyor.

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

	//Kullanýcý bir kiþiye ekstra numara ve ya mail eklemek isterse bu fonksiyon yardýmý ile iþlem gerçekleþtiriliyor.
	//Kullanýcý eklemek istediði kiþinin ismini seçiyor ve ilk olarak girilen isim aranýyor. Eðer isimden 1'den fazla var 
	//ise bir önceki uygulamada olduðu gibi hangisine ekleme yapmak istediði için ekstra bir sorgu gerçekleþtiriliyor.
	//Kullanýcý seçimini yaptýktan sonra eklemek istediði mail ve ya numara deðiþkenini sisteme giriyor. bu sayede istediði
	//kiþiye numara ve ya mail eklemesi geerçekleþtiriliyor. Buradaki option parametresi ile kullanýcýya sorulmadan
	//main içerisinde gerekli baþlýklarda yazýlýmcý tarafýndan verilmiþtir. bu sayede ayrý ayrý fonksiyon yazmak yerine
	//tek fonksiyonda iki iþlem yerine getirilmiþtir. Eklemek istenen deðerler için ekstra bilgilerin tutulduðu
	//deðiþkenlerin doluluk durumu gözleniyor ve bulunan ilk boþta elemana ekleme yapýlýyor.

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
	//Oluþturulan liste, programýn tekrar çalýþtýrýlmasý durumunda hafýzaya alýnabilmek için programýn sonunda kayýt
	//iþlemine tabii tutuluyor.
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
	//Texten veri okumak için yazýlan bir fonksiyon. Texin bütün bir satýrý okunuyor ve kullanýcýnýn istediði karaketere
	//göre string ler parçalanýyor. Bu sayede her bir kiþinin isim, soyisim ,numara gibi deðiþkenleri birbirine karýþmadan
	//tekrar programa çekiliyor.

	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

void list::takeFromtext() {
	//Program tekrar açýldýðýnda bir önceki kiþilerin programa dahi ledilmesini saðlayan fonksiyon. Bu fonksiyon ile kaydedilen
	//text içerisindeki veriler sýrasýyla sisteme çekiliyor ve addfrom text deðiþkeni sayesinde tekrardan içe aktarým saðlanýyor.
	//Text üzerine veriler ',' ler ile yarýlarak yazýlýyor ve okunma iþlemi sýrasýnda bir yukarýdaki fonksiyon sayesinde
	//herbir satýr virgüller yardýmýyla ayrýlýyor ve bir array içerisinde tutuluyor ve ardýndan her bir özellik sisteme aktarýlýyor.
	int index = 0;
	string line;//satýr satýr okuma iþlemi için tanýmlanan deðiþken
	string info[11];//Totalde 11 deet bilgi bulunuyor. Herbirini içerisinde tutmak için oluþturulan array
	ifstream myfile("MyList.txt");//Dosyanýn ismi

	if (myfile.is_open())
	{
		while (myfile.good())
		{

			int countt = 0;//Sistemin baþýnda sýfýrlanýp 10'a kadar gidecek olan index tutucu deðiþken
			const char delim = ',';//virgül ile ayrýlma için kullanýlan deðiþken
			getline(myfile, line);

			std::vector<std::string> out;
			tokenize(line, delim, out);
			//Virgüller ile ayrýlma yapýlýp kiþilerin eklendði kýsým. Her bir satýr için 11 kere dönecek ve herbir elemaný arraye atayacak.
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

	//Kiþi silme için tanýmlanan fonksiyon. Fonksiyon, yine silinmek istenen kiþini ismini kullanýcýya soruyor ve
	//ayný isme aship kiþilerin kontrolü saðlanýyor. Bunun devamýnda o isme aship 1'den fazla kiþi varsa hangisinin 
	//silineceði kullanýcýya soruluyor. Daha sonra o index'te bulunan veriler 'empty' ile dolduruluyor.
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





