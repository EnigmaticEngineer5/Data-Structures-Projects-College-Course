#include "Spotify.h"

int main() {
	cout << "Welcome, this program simulates a quick imitation of a music platform"
		<< "\nwith a play list with some songs added as default!";
	DoublyLinkedBag<Song> songs{};
	songs.add(Song{ "Mirror", "Lil Wayne, Bruno Mars" });
	songs.add(Song{ "Time Stood Still", "Oscuro" });
	songs.add(Song{ "In Memoriam", "Oscuro" });
	songs.add(Song{ "Bring Me Back", "Oscuro" });
	songs.add(Song{ "Paradise Lost", "Oscuro" });

	Spotify playList{ songs };

	const enum Options
	{
		addToBeginning = 1,
		removeBeginning = 2,
		displayListBackward = 3,
		displayListForward = 4,
		rightRotate = 5,
		leftRotate = 6,
		exitProgram = 7
	};

	int selectedOption{};
	do
	{
		cin >> selectedOption;
		while (cin.fail() || selectedOption < 1 || selectedOption > 7)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nPlease select a valid option --> ";
				cin >> selectedOption;
			}
			else
			{
				cout << "\nInvalid range, please re-enter --> ";
				cin >> selectedOption;
			}
		}

		switch (selectedOption)
		{
		case addToBeginning:
			break;

		case removeBeginning:
			break;

		case displayListForward:
			break;

		case displayListBackward:
			break;

		case rightRotate:
			break;

		case leftRotate:
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selectedOption != exitProgram);

	cout << "\n\n";
	return 0;
}