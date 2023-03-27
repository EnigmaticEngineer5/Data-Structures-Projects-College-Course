#include "AssignmentList.h" 

void displayMenu(int&);

int main()
{
	LinkedBag<Assignment> testAssignments{};

	testAssignments.add(Assignment{ "Module 3, Data Structures", Date{3,23,2023} });
	testAssignments.add(Assignment{ "Module 4, Data Structures", Date{4,3,2023} });
	testAssignments.add(Assignment{ "Module 5, Data Structures", Date{4,10,2023} });
	testAssignments.add(Assignment{ "Module 6, Data Structures", Date{4,17,2023} });
	testAssignments.add(Assignment{ "Exam 1, Engineering Probability & Statistics", Date{3,31,2023} });
	testAssignments.add(Assignment{ "Activity 4.1", Date{4,3,2023} });

	AssignmentList toDoList{ testAssignments };

	enum Options
	{
		addNewAssignment = 1,
		removeAssignment = 2,
		displayOrderedList = 3,
		displayList = 4,
		searchNearestAssignments = 5,
		displayAssignmentCount = 6,
		exitProgram = 7
	};

	int selection{};

	cout << "Hey Student!"
		<< "\nA cordial salutation from the Enigmatic Engineer."
		<< "\nThis is the demo of a program that can record a TO-DO list of assignments"
		<< "\nHope you enjoy :)\n";
	do
	{
		displayMenu(selection);

		switch (selection)
		{
		case addNewAssignment:
			toDoList.addAssignment();
			toDoList.displayList();
			break;

		case removeAssignment:
			toDoList.displayList();
			toDoList.removeAssignment();
			toDoList.displayList();
			break;

		case displayOrderedList:
			toDoList.showInDueDateOrder();
			break;

		case displayList:
			toDoList.displayList();
			break;

		case searchNearestAssignments:
			toDoList.displayEarliestAssignments();
			break;

		case displayAssignmentCount:
			cout << "\n\t- You have a total of --> " << toDoList.getAssignmentCount() << " assignments!\n";
			break;

		default:
			cout << "\nExiting program...";
		}
	} while (selection != exitProgram);

	cout << "\n\n";
	return 0;
}

void displayMenu(int& selection)
{
	cout << "\nSelect an option"
		<< "\n\t1) ADD a new assignment"
		<< "\n\t2) REMOVE an assignment"
		<< "\n\t3) Display ORDERED list (based on due dates)"
		<< "\n\t4) Display DEFAULT list"
		<< "\n\t5) Find assignments with EARLIEST DUE DATE"
		<< "\n\t6) Display assignment COUNT"
		<< "\n\t7) Exit program..."
		<< "\n- Answer here --> ";
	cin >> selection;

	while (cin.fail() || selection < 1 || selection > 7)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nThe input must be a string, re-enter --> ";
			cin >> selection;
		}
		else
		{
			cout << "\nPlease enter a valid option between the range --> ";
			cin >> selection;
		}
	}
}