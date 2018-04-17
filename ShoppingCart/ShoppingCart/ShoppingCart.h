#pragma once
#include<string>
#include<vector>
#include"ItemToPurchase.h"
using namespace std;
class ShoppingCart {
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;
	public:
		// Default constructor
		ShoppingCart()
		{
			this->customerName = "none";
			this->currentDate = "January 1, 2016";
		}
		// Parameterized constructor
		ShoppingCart(string customerName, string currentDate)
		{
			this->customerName = customerName;
			this->currentDate = currentDate;
		}
		// function used to return the customer name
		string GetCustomerName(); 
		// function used to get the current date
		string GetDate();
		// function for adding an item to the cart
		void AddItem(ItemToPurchase item);
		// function for removing an item from the cart
		void RemoveItem(string itemName);
		// function for updating the quantity of an item
		void UpdateQuantity(string itemName, int newQuantity);
		// function to get the number of items in the cart
		int GetNumItemsInCart();
		// function to get the total cost of the cart
		int GetCostOfCart();
		// function to print all the items with their prices and with the total
		void PrintTotal();
		// function to print all items with their descriptions
		void PrintDescriptions();
	private:
		// function to print the header of the PrintTotal() and PrintDescriptions() functions
		void PrintHeader();
		// function to get the number of items in the cart
		int GetNumberOfItems();
};