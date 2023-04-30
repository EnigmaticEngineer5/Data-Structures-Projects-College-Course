#pragma once

#include "../Course Source Code/Chapter09/ArrayList/ArrayList.h"

class NiceKid
{
private:
	string kidName;
	ArrayList<string> giftList;

public:
	NiceKid();
	NiceKid(const string, ArrayList<string>);
	~NiceKid();

	NiceKid& addGift();
	NiceKid& removeGift();
	NiceKid& replaceGift();
	void checkIndex(int&);
	
	const int getGiftCount() const;

	NiceKid& setKidName(const string);
	NiceKid& setGiftList(const ArrayList<string>);
	const string getKidName() const;
	const ArrayList<string> getGiftList() const;

	friend istream& operator >> (istream&, NiceKid&);
	friend ostream& operator << (ostream&, const NiceKid&);
};