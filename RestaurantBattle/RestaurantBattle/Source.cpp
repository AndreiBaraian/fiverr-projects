#include<iostream>
#include<vector>
#include<string>
#include<stdbool.h>
using namespace std;

vector<string> restaurants;

void displayRestaurants()
{
	cout << "Here are the current restaurants:" << endl;
	for (int i = 0; i < restaurants.size(); i++)
		cout << "\t" << "\"" << restaurants.at(i) << "\"" << endl;
}

bool Find(string restaurantName)
{
	bool found = false;
	for (int i = 0; i < restaurants.size(); i++)
		if (!restaurants.at(i).compare(restaurantName))
			found = true;
	return found;
}

void addRestaurant()
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to add? ";
	cin.ignore();
	getline(cin, restaurantName);
	if (Find(restaurantName))
		cout << "That restaurant is already on the list, you can not add it again." << endl;
	else
	{
		restaurants.push_back(restaurantName);
		cout << restaurantName << " has been added." << endl;
	}
}

void removeRestaurant()
{
	string restaurantName;
	cout << "What is the name of the restaurant you want to remove? ";
	cin.ignore();
	getline(cin, restaurantName);
	if (!Find(restaurantName))
		cout << "That restaurant is not on the list, you can not remove it." << endl;
	else
	{
		for (int i = 0; i < restaurants.size(); i++)
			if (!restaurants.at(i).compare(restaurantName))
				restaurants.erase(restaurants.begin() + i);
		cout << restaurantName << " has been removed" << endl;
	}
}

vector<string> cutRestaurants()
{
	vector<string> newRestaurants;
	int cutpoint = 0;
	cout << "How many restaurants should be taken from the top and put on the bottom? ";
	cin >> cutpoint;
	if (cutpoint > restaurants.size() || cutpoint < 0)
		cout << "The restaurants can not be cut there, there are only " << restaurants.size() << " restaurants in the list." << endl;
	else
	{
		for (int i = cutpoint; i < restaurants.size(); i++)
			newRestaurants.push_back(restaurants.at(i));
		for(int i=0;i<cutpoint;i++)
			newRestaurants.push_back(restaurants.at(i));
	}
	return newRestaurants;
}

bool isPower()
{
	int n = restaurants.size();
	int p = 1;
	while (p < n)
	{
		p = p * 2;
	}
	if (p == n)
		return true;
	else
		return false;
}

vector<string> shuffleRestaurants()
{
	vector<string> newRestaurants;
	if (!isPower())
	{
		cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove resturants." << endl;
	}
	else
	{
		for (int i = restaurants.size() / 2; i < restaurants.size(); i++)
		{
			newRestaurants.push_back(restaurants.at(i));
			newRestaurants.push_back(restaurants.at(i % (restaurants.size() / 2)));
		}
	}
	return newRestaurants;
}

void tournament()
{
	if (!isPower())
	{
		cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove resturants." << endl;
	}
	else
	{
		vector<string> copyRestaurants;
		vector<string> newRestaurants;
		copyRestaurants = restaurants;
		bool ok = true;
		int round = 1;
		int n = restaurants.size();
		while (ok)
		{
			newRestaurants.clear();
			for (int i = 0; i < n; i+=2)
			{
				int option = 0;
				cout << "Round " << round << ":" << endl;
				cout << "Type \"1\" if you prefer " << copyRestaurants.at(i) << " or" << endl;
				cout << "Type \"2\" if you prefer " << copyRestaurants.at(i + 1) << endl;
				cout << "Choice: ";
				cin >> option;
				while (option != 1 && option != 2)
				{
					cout << "Choice: ";
					cin >> option;
				}
				if (option == 1)
					newRestaurants.push_back(copyRestaurants.at(i));
				else
					newRestaurants.push_back(copyRestaurants.at(i+1));
				round++;
			}
			copyRestaurants = newRestaurants;
			n = copyRestaurants.size();
			if (copyRestaurants.size() == 1)
				ok = false;
		}
		cout << "The winning restaurant is " << copyRestaurants.at(0) << endl;
	}
}

int main()
{
	cout << "Welcome to the restaurant battle!" << endl;
	while (1)
	{
		//display the menu options
		cout << "Please select one of the following options:" << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Display all restaurants" << endl;
		cout << "2 - Add a restaurant" << endl;
		cout << "3 - Remove a restaurant" << endl;
		cout << "4 - \"Cut\" the vector" << endl;
		cout << "5 - \"Shuffle\" the vector" << endl;
		cout << "6 - Begin the tournament" << endl;

		int option = 0;
		cin >> option;
		if (option < 0 || option >6)
			cout << "INVALID SELECTION. Please try again." << endl;
		switch (option)
		{
		case 0:
		{
			exit(4);
		}
		case 1:
			displayRestaurants();
			break;
		case 2:
			addRestaurant();
			break;
		case 3:
			removeRestaurant();
			break;
		case 4:
			restaurants = cutRestaurants();
			break;
		case 5:
			restaurants = shuffleRestaurants();
		case 6:
			tournament();
		}
	}
	return 0;
}