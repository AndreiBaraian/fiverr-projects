#include<iostream>
#include<string>
#include<cstdlib>
#include"ItemToPurchase.h"
#include"ShoppingCart.h"
using namespace std;

void PrintMenu(ShoppingCart shoppingCart)
{
	// Display menu options and wait for user input
	// The loop is executed continously until the user presses q, so he exits the option menu
	while (1)
	{
		// Display options
		cout << endl << "MENU" << endl << endl;
		cout << "a - Add item to cart" << endl << endl;
		cout << "d - Remove item from cart" << endl << endl;
		cout << "c - Change item quantity" << endl << endl;
		cout << "i - Output items' descriptions" << endl << endl;
		cout << "o - Output shopping cart" << endl << endl;
		cout << "q - Quit" << endl << endl << endl;
		cout << "Choose an option: ";
		char option;
		cin >> option;
		// If the input is not good, ask for a valid input
		while (option != 'a' && option != 'd' && option != 'c' && option != 'i' && option != 'o' && option != 'q')
		{
			cout << "Choose an option: ";
			cin >> option;
		}
		switch (option)
		{
		// Output the contents of the shopping cart
		case 'o':
		{
			cout << endl << "OUTPUT SHOPPING CART" << endl << endl;
			shoppingCart.PrintTotal();
			break;
		}
		// Output the items' descriptions
		case 'i':
		{
			cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl << endl;
			shoppingCart.PrintDescriptions();
			break;
		}
		// Add item to the cart
		case 'a':
		{
			string itemName;
			string itemDescription;
			int itemPrice = 0;
			int itemQuantity = 0;
			cout << endl << "ADD ITEM TO CART" << endl << endl;
			cout << "Enter the item name: ";
			cin.ignore();
			getline(cin, itemName);
			cout << endl << "Enter the item description: ";
			getline(cin, itemDescription);
			cout << endl <<"Enter the item price: ";
			cin >> itemPrice;
			cout << endl << "Enter the item quantity: ";
			cin >> itemQuantity;
			ItemToPurchase item1 = ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity);
			shoppingCart.AddItem(item1);
			break;
		}
		// Remove item from the cart
		case 'd':
		{
			string itemName;
			cout << endl << "REMOVE ITEM FROM CART" << endl << endl;
			cout << "Enter name of item to remove: ";
			cin.ignore();
			getline(cin, itemName);
			shoppingCart.RemoveItem(itemName);
			break;
		}
		// Change item quantity
		case 'c':
		{
			string itemName;
			int newQuantity = 0;
			cout << endl << "CHANGE ITEM QUANTITY" << endl << endl;
			cout << "Enter the item name: ";
			cin.ignore();
			getline(cin, itemName);
			cout << endl << "Enter the new quantity: ";
			cin >> newQuantity;
			shoppingCart.UpdateQuantity(itemName, newQuantity);
			break;
		}
		// Exit the option menu
		case 'q':
		{
			exit(4);
		}
		}
	}
}

// main function used to initiate the cart and then transfer the control to the PrintMenu function
int main()
{
	string customerName;
	string currentDate;
	cout << "Enter Customer's Name: ";
	getline(cin, customerName);
	cout << endl << "Enter Today's Date: ";
	getline(cin, currentDate);
	cout << endl << "Customer Name: " << customerName << endl << endl;
	cout << "Today's Date: " << currentDate << endl << endl;
	ShoppingCart shoppingCart1 = ShoppingCart(customerName, currentDate);
	PrintMenu(shoppingCart1);
}