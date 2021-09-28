#include <iostream>
#include "ChildrenBook.h"
#include "ChildrenLibrary.h"
int main()
{
	//Создание книг
	ChildrenBook childrenBooks1{ "Tolkien", "Lord Of The Rings", 25, 1954, 12 };
	ChildrenBook childrenBooks2{ "Azimov", "Foundation", 25, 1942, 12 };
	ChildrenBook childrenBooks3{ "Dostoevskiy", "Crime and punishment", 25, 1866, 18 };
	//Создание массива книг
	ChildrenBook books[]{ childrenBooks1, childrenBooks2, childrenBooks3 };
	//Создание залов 
	ChildrenLibraryHall hall_1{ "hall_1", books, 3 };
	ChildrenLibraryHall hall_2{ "hall_2", books, 3 };
	ChildrenLibraryHall hall_3{ "hall_3", books, 3 };
	//Создание массива залов
	ChildrenLibraryHall halls[]{ hall_1 ,hall_2 , hall_3 };
	//Создание экземпляра библиотеки
	cout << "work";
	ChildrenLibrary library(3, halls);

}