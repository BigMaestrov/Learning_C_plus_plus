#pragma once
#include "ChildrenLibraryHall.h"
#include <iostream>
using namespace std;
class ChildrenLibrary
{
private:
	int numOfHalls;
	ChildrenLibraryHall** halls;
	int numBooksInLibrary;
	ChildrenBook** booksInLibrary;
	int* numBooksInHalls;

public:

	void addHalls(int sizeArray, ChildrenLibraryHall newHalls[]) {
		for (int i = 0; i < sizeArray; i++) {
			halls[i] = &newHalls[i];
		}
	}

	void setNumBookInLibrary(int numBook) {
		numBooksInLibrary = numBook;
	}

	int getNumBookInLibrary() {
		return numBooksInLibrary;
	}
	void printNamesOfHallsAndNumOfBooks(){
		for (int i = 0; i < numOfHalls; i++) {
			cout << halls[i]->getNameOfHall() << " "<<halls[i]->getNumOfBooks();
		}
	}

	void reductHall(int i, ChildrenLibraryHall newHall) {
		halls[i] = &newHall;
	}

	void reductBook(int i,ChildrenBook book) {
		booksInLibrary[i] = &book;
	}

	void addBookToLibrary(int i, ChildrenBook book) {
		booksInLibrary[i] = &book;
	}

	void deleteBookFromLibrary(int i, ChildrenBook book) {
		delete booksInLibrary[i];
	}

	ChildrenBook* getBestBook() {
		int max = INT16_MIN;
		int indexOfMax = -1;
		for (int i = 0; i < getNumBookInLibrary(); i++) {
			if (booksInLibrary[i]->getCost() > max) {
				max = booksInLibrary[i]->getCost();
				indexOfMax = i;
			}
		}
		return booksInLibrary[indexOfMax];
	}

	ChildrenBook* getBookByNum(int num) {
		return booksInLibrary[num];
	}

	ChildrenLibraryHall** getHalls() {
		return halls;
	}

	ChildrenLibraryHall* getHallsByNum(int num) {
		return halls[num];
	}

	void setNumOfHalls(int numOfHall) {
		numOfHalls = numOfHall;
	}

	int getNumOfHalls() {
		return numOfHalls;
	}

	void setNumBooksInHalls(int numBooksInHall[]) {
		for (int i = 0; i < getNumOfHalls(); i++) {
			numBooksInHalls[i] = numBooksInHall[i];
		}
	}

	int* getNumBooksInHalls() {
		return numBooksInHalls;
	}

	int getCostOfAllBooks() {
		int cost = 0;
		for (int i = 0; i < getNumOfHalls(); i++) {
			cost += halls[i]->getCostOfHall();
		}
		return cost;
	}

	//принимающий количество залов и массив количеств книг по залам;
	ChildrenLibrary(int numOfHalls, int numBooksAtHalls[])
	{
		halls = new ChildrenLibraryHall * [numOfHalls];
		booksInLibrary = new ChildrenBook * [0];
		for (int i = 0; i < numOfHalls; i++) {
			halls[i] = new ChildrenLibraryHall();
		}
		numBooksInHalls = new int[numOfHalls];
		setNumBookInLibrary(0);
		setNumOfHalls(numOfHalls);
		setNumBooksInHalls(numBooksAtHalls);
	}
	//принимающий массив залов  и размер массива;
	ChildrenLibrary(int sizeArray, ChildrenLibraryHall newHalls[])
	{
		halls = new ChildrenLibraryHall * [sizeArray];
		for (int i = 0; i < sizeArray; i++) {
			halls[i] = new ChildrenLibraryHall();
		}
		booksInLibrary = new ChildrenBook * [0];
		numBooksInHalls = new int[sizeArray];
		setNumBookInLibrary(0);
		setNumOfHalls(sizeArray);
		setNumBooksInHalls(0);
	}

	//Конструктор копирования.
	ChildrenLibrary(const ChildrenLibrary &library)
	{
		halls = new ChildrenLibraryHall * [library.numOfHalls];
		for (int i = 0; i < library.numOfHalls;i++) {
			halls[i] = new ChildrenLibraryHall();
			halls[i] = library.halls[i];
		}
		booksInLibrary = new ChildrenBook * [0];
		numBooksInHalls = new int[library.numOfHalls];
		setNumBookInLibrary(library.numBooksInLibrary);
		setNumOfHalls(library.numOfHalls);
		setNumBooksInHalls(library.numBooksInHalls);
	}

	void deleteHaLLs() {
		for (int i = 0; i < numOfHalls; i++) {
			delete[] halls[i];
		}
		delete[] halls;
	}

	void deleteBooksInLibrary() {
		for (int i = 0; i < numBooksInLibrary; i++) {
			delete[] booksInLibrary[i];
		}
		delete[] booksInLibrary;
	}

	void deleteNumBooksInHalls() {
		delete[] numBooksInHalls;
	}

	//Деструктор
	~ChildrenLibrary() {
		deleteHaLLs();
		deleteBooksInLibrary();
		deleteNumBooksInHalls();
	}
};

