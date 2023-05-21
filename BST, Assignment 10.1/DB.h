#pragma once

#include "BinarySearchTree.h"
#include "PersonInfo.h"

class DB
{
private:
	BinarySearchTree<PersonInfo> BST;
	int numberOfPeople;

public:
	DB();
	DB(const BinarySearchTree<PersonInfo>&, const int);
	DB(const DB&);
	~DB();
	DB& operator = (const DB&);

	DB& setBST(const BinarySearchTree<PersonInfo>&);
	DB& setNumberOfPeople(const int);
	const BinarySearchTree<PersonInfo> getBST() const;
	const int getNumberOfPeople() const;

	//Basic requirements
	void addPerson();
	void removePerson();
	void searchPerson() const;
	void modifyPerson();
	void displayPerson() const;
	void displayInBirthdayOrder() const;

	//Additional improvements
	void displayInNameOrder() const;
	void simulate();
	void preorderDisplay() const;
	void postorderDisplay() const;
	void eraseDatabase();
};