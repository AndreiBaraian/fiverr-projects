#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int SLOT0 = 100;
const int SLOT1 = 500;
const int SLOT2 = 1000;
const int SLOT3 = 0;
const int SLOT4 = 10000;
const int SLOT5 = 0;
const int SLOT6 = 1000;
const int SLOT7 = 500;
const int SLOT8 = 100;


double ComputeWinnings(int slot)
{
	double result = 0;
	switch (slot)
	{
	case 0:
		result = SLOT0;
		break;
	case 1:
		result = SLOT1;
		break;
	case 2:
		result = SLOT2;
		break;
	case 3:
		result = SLOT3;
		break;
	case 4:
		result = SLOT4;
		break;
	case 5:
		result = SLOT5;
		break;
	case 6:
		result = SLOT6;
		break;
	case 7:
		result = SLOT7;
		break;
	case 8:
		result = SLOT8;
		break;
	}
	return result;
}

double OneChipFalling(int slot)
{
	for (int i = 0; i < 12; i++)
	{
		if (slot == 0)
		{
			slot += 0.5;
			continue;

		}
		if (slot == 8)
		{
			slot -= 0.5;
			continue;
		}

		int numberRandom = rand();
		if (numberRandom % 2 == 1)
		{
			slot += 0.5;
		}
		else
		{
			slot -= 0.5;
		}
	}
	return ComputeWinnings(slot);
}

double MultipleChipsFalling(int amountOfChips, int slot)
{
	int totalWinnings = 0;
	for (int i = 0; i < amountOfChips; i++)
	{
		//double chipLocation2 = slot;

		//totalWinnings += chipFinalLocation2;
		totalWinnings += OneChipFalling(slot);
	}
	return totalWinnings;
}

int chipsInput()
{
	int amountOfChips = 0;
	cout << "How many chips do you want to drop (>0)? ";
	cin >> amountOfChips;
	while (amountOfChips < 0)
	{
		cout << "Invalid number of chips, please try again." << endl << endl;
		cout << "How many chips do you want to drop (>0)? ";
		cin >> amountOfChips;
	}
	return amountOfChips;
}

int slotInput()
{
	int slot = 0;
	cout << "Which slot do you want to drop the chip(s) in (0-8)? ";
	cin >> slot;
	while (slot > 8 || slot < 0)
	{
		cout << "Invalid slot, please try again." << endl << endl;
		cout << "Which slot do you want to drop the chip(s) in (0-8)? ";
		cin >> slot;
	}
	return slot;
}

int selectionInput()
{
	int selection = 0;
	cout << endl << "Enter your selection now: ";
	cin >> selection;
	while (selection < 0 || selection > 3)
	{
		cout << "Invalid selection. Please enter 0, 1, 2 or 3" << endl << endl;
		cout << "Enter your selection now: ";
		cin >> selection;
	}
	return selection;
}

int main()
{
	srand(42);//Declaring constant variables for the prizes as per lab description

	cout << "Welcome to the Plinko simulator!" << endl << endl;
	int selection = 0;
	while(1)
	{
		cout << "Menu: Please select one of the following options:" << endl << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;
		cout << "3 - Drop multiple chips into each slot" << endl << endl;
		selection = selectionInput();
		switch (selection)
		{
			//Quits the game
		case 0:
		{
			cout << endl << "Goodbye!" << endl;
			return 0;
			break;
		}
		//Part 2 - Let the Chips Fall 
		case 1:
		{
			cout << endl << "*** Drop single chip ***" << endl << endl;
			int slot = slotInput();
			cout << fixed << setprecision(2) << "Winnings: $" << OneChipFalling(slot) << endl << endl;
			break;
		}
		//Part 3 - Bowl of Chips
		case 2:
		{
			cout << endl << "*** Drop multiple chips ***" << endl << endl;
			int amountOfChips = chipsInput();
			//This part is another verification for a valid slot
			int slot2 = slotInput();
			double totalWinnings = MultipleChipsFalling(amountOfChips, slot2);
			cout << fixed << setprecision(2) << "Total winnings on " << amountOfChips << " chips: " << totalWinnings << endl;
			double averagePerChip = totalWinnings / amountOfChips;
			cout << fixed << setprecision(2) << "Average winnings per chip: " << averagePerChip << endl << endl;
			break;
		}
		case 3:
		{
			cout << endl << "*** Sequentially drop multiple chips ***" << endl << endl;
			int amountOfChips2 = chipsInput();
			for (int i = 0; i < 9; i++)
			{
				double totalWinnings = MultipleChipsFalling(amountOfChips2, i);
				cout << fixed << setprecision(2) << "Total winnings on slot " << i << " chips: " << totalWinnings <<endl;
				double averagePerChip = totalWinnings / amountOfChips2;
				cout << fixed << setprecision(2) << "Average winnings per chip: " << averagePerChip << endl << endl;
			}
		}
		}
	}
	return 0;
}
