#include "Spotify.h"

Spotify::Spotify() : songList{} {};
Spotify::Spotify(DoublyLinkedBag<Song> sourceList) : songList{ sourceList } {};
Spotify::~Spotify() {};

Spotify& Spotify::addSongToBeginning()
{
	Song newSong{};
	cin >> newSong;
	this->songList.addToBeginning(newSong);
	return *this;
}
Spotify& Spotify::removeSongFromBeiginning()
{
	// TODO: insert return statement here
}

void Spotify::playNext()
{
	if (songList.getNodePosition() != songList.getCurrentSize())
	{
		cout << songList.getRightItem();
	}
	else
	{
		cout << "\n\nPlaylist finished, no more songs after!";
	}
}

void Spotify::playPrevious()
{
	if (songList.getNodePosition() > 0)
	{
		cout << songList.getLeftItem();
	}
	else
	{
		cout << "\n\nThere are no more songs before!";
	}
}

void Spotify::displayPlaylist() const
{
	for (int i{}; i < getSongList().getCurrentSize(); i++)
	{
		cout << '\n' << (i + 1) << ") Song: " << getSongList().getItem(i).getSongName()
			<< ", by Artist: " << getSongList().getItem(i).getSongArtist();
	}
}

void Spotify::printListBackwards() const
{
}

const DoublyLinkedBag<Song> Spotify::getSongList() const
{
	return songList;
}