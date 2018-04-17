#include"ShoppingCart.h"
#include<stdbool.h>
#include<iostream>

string ShoppingCart::GetCustomerName()
{
	return this->customerName;
}

string ShoppingCart::GetDate()
{
	return this->currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item)
{
	this->cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName)
{
	bool found = false;
	for (int i = 0; (unsigned)i < this->cartItems.size(); i++)
	{
		if (this->cartItems.at(i).GetName() == itemName)
		{
			found = true;
			this->cartItems.erase(cartItems.begin() + i);
		}
	}
	if (!found)
	{
		cout << endl << "Item not found in cart. Nothing removed." << endl << endl;
	}
}

void ShoppingCart::UpdateQuantity(string itemName, int newQuantity)
{
	bool found = false;
	for (int i = 0; (unsigned)i < this->cartItems.size(); i++)
	{
		if (this->cartItems.at(i).GetName() == itemName)
		{
			found = true;
			this->cartItems.at(i).SetQuantity(newQuantity);
		}
	}
	if (!found)
	{
		cout << endl << "Item not found in cart. Nothing modified." << endl << endl;
	}
}

int ShoppingCart::GetNumItemsInCart()
{
	return this->cartItems.size();
}

int ShoppingCart::GetCostOfCart()
{
	int totalCost = 0;
	if (this->cartItems.size() == 0)
	{
		return totalCost;
	}
	for (int i = 0; (unsigned)i < this->cartItems.size(); i++)
	{
		totalCost += this->cartItems.at(i).GetPrice() * this->cartItems.at(i).GetQuantity();
	}
	return totalCost;
}

void ShoppingCart::PrintHeader()
{
	cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl << endl;
}

int ShoppingCart::GetNumberOfItems()
{
	int numberOfItems=0;
	for(int i = 0; (unsigned)i < this->cartItems.size(); i++)
		numberOfItems += this->cartItems.at(i).GetQuantity();
	return numberOfItems;
}

void ShoppingCart::PrintTotal()
{
	this->PrintHeader();
	cout << "Number of Items: " << GetNumberOfItems() << endl << endl;
	if(GetNumberOfItems() == 0)
	{
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	else
	{
		for (int i = 0; (unsigned)i < this->cartItems.size(); i++)
		{
			this->cartItems.at(i).PrintItemCost();
			cout << endl;
		}
	}
	cout << endl << "Total: $" << this->GetCostOfCart() << endl << endl;
}

void ShoppingCart::PrintDescriptions()
{
	this->PrintHeader();
	cout << endl;
	cout << "Item Descriptions" << endl << endl;
	for (int i = 0; (unsigned)i < this->cartItems.size(); i++)
	{
		this->cartItems.at(i).PrintItemDescription();
		cout << endl;
	}
}