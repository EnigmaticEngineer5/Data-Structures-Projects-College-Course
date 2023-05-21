#pragma once

#include "../CircularList, Assignment 6.2/LinkedList.h"

class NiceKid
{
private:
	string kidName;
	LinkedList<string> giftList;

public:
	NiceKid() = default;
	~NiceKid() = default;

	NiceKid& addGift();
	NiceKid& removeGift();
	NiceKid& replaceGift();
	void checkIndex(int&);
	
	const int getGiftCount() const;

	NiceKid& setKidName(const string);
	NiceKid& setGiftList(const LinkedList<string>&);
	const string getKidName() const;

	friend istream& operator >> (istream&, NiceKid&);
	friend ostream& operator << (ostream&, const NiceKid&);
};