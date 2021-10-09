#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H
namespace Temp {
	template <class T>
	class Insertion {
	public:
		Insertion();
		Insertion(int size);
		void addElement(const T& element);
		void showElements();
		void sortElement();
		bool isFull();
		void delArray();

	private:
		T *arraysort;
		int sizearray;
		int used ;



	};

}


#endif