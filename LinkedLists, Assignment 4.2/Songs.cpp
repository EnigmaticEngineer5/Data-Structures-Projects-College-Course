#include "Songs.h"

Song::Song(const string sourceSong, const string sourceArtist) :
	songName{ sourceSong }, songArtist{ sourceArtist } {};
Song::~Song() {};

Song& Song::operator=(const Song& sourceSong)
{
	this->setSongName(sourceSong.getSongName()).setSongArtist(sourceSong.getSongArtist());
}

Song& Song::setSongName(const string sourceSong)
{
	this->songName = sourceSong;
	return *this;
}

Song& Song::setSongArtist(const string sourceArtist)
{
	this->songArtist = sourceArtist;
	return *this;
}

const string Song::getSongName() const
{
	return songName;
}

const string Song::getSongArtist() const
{
	return songArtist;
}

const bool Song::operator==(const Song& sourceSong) const
{
	return (songName.compare(sourceSong.getSongName()) == 0);
}

istream& operator>>(istream& input, Song& sourceSong)
{
	cout << "\n\t- Enter the SONG --> ";
	input >> sourceSong.songName;

	cout << "\t- Enter the ARTIST --> ";
	return input >> sourceSong.songArtist;
}

ostream& operator<<(ostream& output, const Song& sourceSong)
{
	return output << "\n\t- Now Playing --> " << sourceSong.getSongName()
		<< " by " << sourceSong.getSongArtist();
}