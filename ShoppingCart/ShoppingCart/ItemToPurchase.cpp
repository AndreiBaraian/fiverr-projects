#include"ItemToPurchase.h"
#include<iostream>

ItemToPurchase::ItemToPurchase()
{
	this->itemDescription = "none";
	this->name = "none";
	this->price = 0;
	this->quantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string itemDescription, int price, int quantity)
{
	ItemToPurchase();
	this->name = name;
	//this->itemDescription = itemDescription;
	SetDescription(itemDescription);
	this->price = price;
	this->quantity = quantity;
}

void ItemToPurchase::SetDescription(string itemDescription)
{
	this->itemDescription = itemDescription;
}

string ItemToPurchase::GetDescription()
{
	return this->itemDescription;
}

void ItemToPurchase::SetName(string name)
{
	this->name = name;
}

string ItemToPurchase::GetName()
{
	return this->name;
}

void ItemToPurchase::SetPrice(int price)
{
	this->price = price;
}

int ItemToPurchase::GetPrice()
{
	return this->price;
}

void ItemToPurchase::SetQuantity(int quantity)
{
	this->quantity = quantity;
}

int ItemToPurchase::GetQuantity()
{
	return this->quantity;
}

void ItemToPurchase::PrintItemCost()
{
	int subtotal = 0;
	subtotal = quantity*price;
	cout << this->name << " " << this->quantity << " @ $" << this->price << " = $" << subtotal << endl;
}

void ItemToPurchase::PrintItemDescription()
{
	cout << this->name << ": " << this->GetDescription() << endl;
}