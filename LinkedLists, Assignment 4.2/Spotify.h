#pragma once

#include "DoublyLinkedBag.h"
#include "Songs.h"

class Spotify
{
private:
	DoublyLinkedBag<Song> songList;

public:
	Spotify();
	Spotify(DoublyLinkedBag<Song>);
	~Spotify();

	Spotify& addSongToBeginning();
	Spotify& removeSongFromBeiginning();

	void playNext();
	void playPrevious();

	void displayPlaylist() const;
	void printListBackwards() const;

	const DoublyLinkedBag<Song> getSongList() const;
};