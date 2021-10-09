/*Program gereði birçok fonksiyon tanýmlanmasý gerekiyor. Bu durumda tek main üzerinde iþlem yaparken sürekli aþaðý
yukarý gidip gelme, hata durumunda hatanýn farkýna varýlma durumlarý büyük sýkýntý yaratmýþtý bir önceki projede.Bu sebeple
bu projede hash table iþlemi için ayrý bir kütüphane yazma ve bu kütüphane dosyalarý ile iþlemleri gerçekleþtirmek
sürecin gidiþatý için daha kolaylýk saðlamýþ ve hata durumlarýnýn analizini benim için daha kolay hale getirmiþtir.
Bu sebeple kütüphane yazma gereksinimi duydum.

Header .h uzantýlý bu yapýda oluþturacaðým class'ýn constructor ve diðer gerekli deðiþkenleri oluþturuldu. Ayný zamanda
kullanýlacak olan fonksiyonlar paarmetreleri ile beraber burada tanýmlandý.
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

	/*Kullanýcýnýn numaraya göre arama yapma durumu olduðunda yapýmýz Hash mantýðýndan çýkmaktaydý. bu sebeple
	sadece kiþinin numarasýný ve o kiþinin index deðerini ttan bir baþka hash yapýsý daha oluþturdum.bu sayede
	kullanýcý numaraya göre arama yapabilecek. Bunun için birincil telefon numarasý referans alýnacaktýr.Diðer
	ektra numaralar için de arama iþlemi yapýlabilirdi ama bu sefer baya fazla array tanýmlamasý yapmam gerekecekti.Genel
	mantýðý ayný olmasý sebebiyle bir tane oluþturmak yeterli geldiði için böyle bir sistem yaptým.*/
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
