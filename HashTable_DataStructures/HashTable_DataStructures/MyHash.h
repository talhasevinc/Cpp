/*Program gere�i bir�ok fonksiyon tan�mlanmas� gerekiyor. Bu durumda tek main �zerinde i�lem yaparken s�rekli a�a��
yukar� gidip gelme, hata durumunda hatan�n fark�na var�lma durumlar� b�y�k s�k�nt� yaratm��t� bir �nceki projede.Bu sebeple
bu projede hash table i�lemi i�in ayr� bir k�t�phane yazma ve bu k�t�phane dosyalar� ile i�lemleri ger�ekle�tirmek
s�recin gidi�at� i�in daha kolayl�k sa�lam�� ve hata durumlar�n�n analizini benim i�in daha kolay hale getirmi�tir.
Bu sebeple k�t�phane yazma gereksinimi duydum.

Header .h uzant�l� bu yap�da olu�turaca��m class'�n constructor ve di�er gerekli de�i�kenleri olu�turuldu. Ayn� zamanda
kullan�lacak olan fonksiyonlar paarmetreleri ile beraber burada tan�mland�.
*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>


using namespace std;
class list {
private:
	static const int tableSize = 100;
	static const int tableSize2 = 100;
	struct item {

		string name;
		string surname;
		string address;
		string mail[4];
		string phone_number[4];
		item* next;
	};

	/*Kullan�c�n�n numaraya g�re arama yapma durumu oldu�unda yap�m�z Hash mant���ndan ��kmaktayd�. bu sebeple
	sadece ki�inin numaras�n� ve o ki�inin index de�erini ttan bir ba�ka hash yap�s� daha olu�turdum.bu sayede
	kullan�c� numaraya g�re arama yapabilecek. Bunun i�in birincil telefon numaras� referans al�nacakt�r.Di�er
	ektra numaralar i�in de arama i�lemi yap�labilirdi ama bu sefer baya fazla array tan�mlamas� yapmam gerekecekti.Genel
	mant��� ayn� olmas� sebebiyle bir tane olu�turmak yeterli geldi�i i�in b�yle bir sistem yapt�m.*/
	struct item2 {
		string num;
		int index;

	};
	item* HashTable[tableSize];
	item2* NumberTable[100];

public:
	list();
	int Hash(string key);
	void AddItemList(string name, string surname, string address, string mail, string phone);

	void ShowList();
	void FindPerson(string word, char select);
	void deletePerson(string name);
	void editPerson(string name, string state, int i);
	void addExtra(string name, string word, int option);
	void writeTex();
	void AddItemListfromtext(string name, string surname, string address, string mail, string mail1, string
		mail2, string mail3, string phone, string phone1, string phone2, string phone3);
	void takeFromtext();
	void tokenize(std::string const& str, const char delim,
		std::vector<std::string>& out);

};
#pragma once
