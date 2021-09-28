#pragma once
#include "ChildrenBook.h"
#include <string>;
#include <iostream>;
using namespace std;
class ChildrenLibraryHall
{
private:
	int numOfBooks;
	ChildrenBook** booksInHall;
	string nameOfHall;

public:

	void setNameOfHall(string nameOfHal1) {
		nameOfHall = nameOfHal1;
	}

	string getNameOfHall() {
		return nameOfHall;
	}

	void setNumOfBooks(int numOfBook) {
		numOfBooks = numOfBook;
	}

	int getNumOfBooks() {
		return numOfBooks;
	}

	void makeArray(ChildrenBook* childBooks) {
		for (int i = 0; i < numOfBooks; i++) {
			booksInHall[i] = new ChildrenBook;
			booksInHall[i] = &childBooks[i];
		}
	}

	void makeArray(int numOfBook) {
		for (int i = 0; i < numOfBook; i++) {
			booksInHall[i] = new ChildrenBook;
		}
	}

	//принимающий им€ зала и кол - во книг в зале;
	ChildrenLibraryHall(string nameOfHall, int numOfBooks)
	{
		booksInHall = new ChildrenBook * [numOfBooks];
		for (int i=0; i < numOfBooks; i++) {
			booksInHall[i] = new ChildrenBook();
		}
		setNameOfHall(nameOfHall);
		setNumOfBooks(numOfBooks);
		makeArray(numOfBooks);
	}
	//принимающий им€ зала, массив книг и размер массива;
	ChildrenLibraryHall(string nameOfHall, ChildrenBook childBooks[], int numOfBooks)
	{
		booksInHall = new ChildrenBook * [numOfBooks];
		for (int i=0; i < numOfBooks; i++) {
			booksInHall[i] = new ChildrenBook();
		}
		setNameOfHall(nameOfHall);
		setNumOfBooks(numOfBooks);
		makeArray(childBooks);
	}
	// онструктор копировани€.
	ChildrenLibraryHall(const ChildrenLibraryHall &hall)
	{
		booksInHall = new ChildrenBook * [hall.numOfBooks];
		for (int i=0; i < 1; i++) {
			booksInHall[i] = new ChildrenBook();
			booksInHall[i] = hall.booksInHall[i];
		}
		setNameOfHall(hall.nameOfHall);
		setNumOfBooks(hall.numOfBooks);
		booksInHall = hall.booksInHall;
	}

	// онструктор по умолчанию.
	ChildrenLibraryHall()
	{
		booksInHall = new ChildrenBook * [1];
		for (int i=0; i < 1;i++) {
			booksInHall[i] = new ChildrenBook();
		}
		setNameOfHall("defaultName");
		setNumOfBooks(0);
		booksInHall = 0;
	}

	////ƒеструктор
	//~ChildrenLibraryHall() {
	//	for (int i = 0; i < numOfBooks; i++) {
	//		delete[] booksInHall[i];
	//	}
	//	delete[] booksInHall;
	//}

	void printNameBooks() {
		for (int i = 0; i < numOfBooks; i++) {
			std::cout << booksInHall[i]->getName() << " ";
		}
	}

	int getCostOfHall() {
		int costOfHall = -1;
		for (int i = 0; i < numOfBooks; i++) {
			costOfHall += booksInHall[i]->getCost();
		}
		return costOfHall;
	}

	ChildrenBook* getBookByNum(int num) {
		return booksInHall[num];
	}

	void setBookByNum(int num, ChildrenBook newBook) {
		booksInHall[num] = &newBook;
	}

	void addBookByNum(int num, ChildrenBook newBook) {
		booksInHall[num] = &newBook;
	}

	void deleteBookByNum(int num, ChildrenBook newBook) {
		delete booksInHall[num];
	}

	ChildrenBook* getBestBook() {
		int max = INT16_MIN;
		int indexOfMax = -1;
		for (int i = 0; i < numOfBooks; i++) {
			if (booksInHall[i]->getCost() > max) {
				max = booksInHall[i]->getCost();
				indexOfMax = i;
			}
		}
		return booksInHall[indexOfMax];
	}
};

