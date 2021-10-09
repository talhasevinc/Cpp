// ConsoleApplication5.cpp : Bu dosya 'main' iþlevi içeriyor. Program yürütme orada baþlayýp biter.
//

#include <iostream>
#include <ctype.h>
#include "Template.h"
#include "Template.cpp"
using namespace std;

using Temp::Insertion;
int main()
{
	std::cout << "Welcome insertion sort algorithm...\n";
	int sizeArray;
	int select;
	cout << "Which of type sorting?\n1-)Alphabet  2-)Numeric    Selection:  ";
	cin >> select;


	cout << "Please enter number of array size you want. Input must be digit:";

	cin >> sizeArray;
	if (select == 1) {

		Insertion<char>arrayOne(sizeArray);

		char number;
		char selection = ' ';
		do {

			cout << "Enter input you want add to array:";

			cin >> number;

			arrayOne.addElement(number);
			bool end = arrayOne.isFull();
			if (end)
			{
				char del;
				cout << "Array is full. Do you want delete array?()Y/N):";

				cin >> del;
				if (del == 'Y' || del == 'y')
				{
					arrayOne.delArray();
				}

				else {
					cout << "GoodBye Sir...";
					exit(1);
				}
			}
			else {
				cout << "\nDo you want contiune(Y/N):";
				cin >> selection;
			}

		} while (selection != 'N' && selection != 'n');


	}
	else if (select == 2) {
		Insertion<int>arrayOne(sizeArray);


		int number;
		char selection = ' ';
		do {

			cout << "Enter input you want add to array:";

			cin >> number;

			arrayOne.addElement(number);
			bool end = arrayOne.isFull();
			if (end)
			{
				char del;
				cout << "Array is full. Do you want delete array?()Y/N):";

				cin >> del;
				if (del == 'Y' || del == 'y')
				{
					arrayOne.delArray();
				}

				else {
					cout << "GoodBye Sir...";
					exit(1);
				}
			}
			else {
				cout << "\nDo you want contiune(Y/N):";
				cin >> selection;
			}

		} while (selection != 'N' && selection != 'n');
	}
}
