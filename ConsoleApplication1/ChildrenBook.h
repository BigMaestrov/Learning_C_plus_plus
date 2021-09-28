#pragma once
#include <string>;
using namespace std;
class ChildrenBook
{
private:
	string author;
	string name;
	int cost;
	int year;
	int minimalAge;

public:
	void setAuthor(string author_Name) {
		author = author_Name;
	}

	string getAuthor() {
		return author;
	}


	void setName(string name_book) {
		name = name_book;
	}

	string getName() {
		return name;
	}

	void setCost(int cost_book) {
		cost = cost_book;
	}

	int getCost() {
		return cost;
	}

	void setMinimalAge(int minimalAge_book) {
		cost = minimalAge_book;
	}

	int getMinimalAge() {
		return minimalAge;
	}

	void setYear(int date_year) {
		year = date_year;
	}

	int getYear() {
		return year;
	}

	ChildrenBook()
	{
		setAuthor("Не определено");
		setName("Не определено");
		setCost(0);
		setYear(0);
		setMinimalAge(0);
	}

	ChildrenBook(string author, string name, int cost, int year, int minimalAge)
	{
		setAuthor(author);
		setName(name);
		setCost(cost);
		setYear(year);
		setMinimalAge(minimalAge);
	}

	ChildrenBook(string author, int year)
	{
		ChildrenBook childrenBook{};
		childrenBook.setAuthor(author);
		childrenBook.setYear(year);
	}

};

