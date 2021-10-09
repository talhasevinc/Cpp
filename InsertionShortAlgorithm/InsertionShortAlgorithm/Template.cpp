#include "Template.h"
#include <iostream>

using std::cout;
using std::endl;
namespace Temp {

	template<class T>
	Insertion<T>::Insertion()
		:sizearray(20),used(0)
	{
		arraysort = new T[sizearray];
		


	}

	template<class T>
	Insertion<T>::Insertion(int size)
		:sizearray(size),used(0)
	{

		arraysort = new T[sizearray];
	}

	template<class T>
	void Insertion<T>::addElement(const T& element)
	{
		if (sizearray <= used)
		{
			cout << "Array is full. You can't add any element..." << endl;

		}

		else
		{

			arraysort[used] = element;
			used++;
			sortElement();
			showElements();

		}

	}
	template<class T>
	void Insertion<T>::showElements()
	{
		for (int i = 0; i < used; i++)
		{
			cout << arraysort[i] <<" ";
		}

	}

	template<class T>
	void Insertion<T>::sortElement()
	{
		if (used > 1)
		{
			int i = 0;
			T addedElement = arraysort[used - 1];
			while (!(addedElement < arraysort[i]) )
			{
				++i;
				if (used == i)
					break;

			}

			for (int slide = used-1; slide > i; slide--)
			{
				
				arraysort[slide] = arraysort[slide-1];

			}

			arraysort[i] = addedElement;
		}

	}


	template<class T>
	bool Insertion<T>::isFull()
	{
	
		if (used == sizearray)
		{
			return true;
		}

		return false;
	}


	template<class T>
	void Insertion<T>::delArray()
	{
	  
		delete [] arraysort;
		arraysort = new T[sizearray];
		used = 0;
	
	
	}

}