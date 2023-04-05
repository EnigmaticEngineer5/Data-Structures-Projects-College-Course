#pragma once

#include <iostream>
using namespace std;

class Song
{
private:
	string songName;
	string songArtist;

public:
	Song(const string = "", const string = "");
	~Song();
	Song& operator = (const Song&);

	Song& setSongName(const string);
	Song& setSongArtist(const string);
	const string getSongName() const;
	const string getSongArtist() const;

	const bool operator == (const Song&) const;

	friend istream& operator >> (istream&, Song&);
	friend ostream& operator << (ostream&, const Song&);
};

