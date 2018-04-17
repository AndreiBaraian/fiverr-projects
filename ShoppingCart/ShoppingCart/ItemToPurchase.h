#pragma once
#include<string>
using namespace std;
class ItemToPurchase {
	string itemDescription;
	string name;
	int price;
	int quantity;
	public:
		// Default constructor
		ItemToPurchase();
		// Parameterized constructor
		ItemToPurchase(string name, string itemDescription, int price, int quantity);
		// function to set the description of the item
		void SetDescription(string itemDescription);
		// function to return the description of the item
		string GetDescription();
		// function to set the name of the item
		void SetName(string name);
		// function to return the name of the item
		string GetName();
		// function to set the price of the item
		void SetPrice(int price);
		// function to return the price of the item
		int GetPrice();
		// function to set the quantity of the item
		void SetQuantity(int quantity);
		// function to get the quantity of the item
		int GetQuantity();
		// function to print the cost of the item
		void PrintItemCost();
		// function to print the description of the item
		void PrintItemDescription();
};