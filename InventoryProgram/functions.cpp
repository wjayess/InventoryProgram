#include "main.h"
#include <fstream>
#include <string>

using namespace std;

// Main menu function. Basically a bunch of couts and cins to then call the MenuThink() function, which does the hard work.
void DisplayMenu(ItemList items)
{
	char menuChoice;
	char validChars[14] = { 'R', 'r', 'I', 'i', 'U', 'u', 'D', 'd', 'P', 'p', 'W', 'w', 'Q', 'q' };
	bool wait = false;

	// Input validation loop (so it doesn't end the program if the user enters an invalid option)
	while (!wait)
	{
		wait = true;

		cout << "Please choose an option:\n"
			"--------\n"
			"R -- Read existing data and add to the list\n"
			"I -- Insert a new item in the list\n"
			"U -- Update the number of units of a given item\n"
			"D -- Delete an existing item\n"
			"P -- Print all of the items in stock and the number of units of each\n"
			"W -- Write a new list back to the file\n"
			"Q -- Quit\n";

		cin >> menuChoice;

		// Utilizing the std::find(), std::begin(), and std::end() functions to see if the user's input is one of the chars within the validChars[] array.
		bool menuChoiceExists = find(begin(validChars), end(validChars), menuChoice) != end(validChars);

		// If it doesn't exist, cout an error and restart the loop
		if (!menuChoiceExists)
		{
			cout << "Please enter a valid option!\n";

			wait = false;
		}
		else
			MenuThink(menuChoice, items);
	}
}

// Does the thinking of the choices. Basically, just a switch statement that calls all the functions if the corresponding char is chosen by the user.
void MenuThink(char menuChoice, ItemList items)
{
	switch (menuChoice)
	{
	case 'R':
	case 'r':
		ReadListData(items);

		break;
	case 'I':
	case 'i':
		InsertListData(items);

		break;
	case 'U':
	case 'u':
		UpdateInStockAmount(items);

		break;
	case 'D':
	case 'd':
		DeleteListData(items);

		break;
	case 'P':
	case 'p':
		PrintInStock(items);

		break;
	case 'W':
	case 'w':
		WriteListData(items);

		break;
	case 'Q':
	case 'q':
		exit(0);

		break;
	}
}

// Reads the file data and appends nodes within the linked list within memory.
void ReadListData(ItemList items)
{
	items.ReadItems();

	cout << "Finished reading file data.\n";

	DisplayMenu(items);
}

// Inserts a node with the given data from the user.
void InsertListData(ItemList items)
{
	double itemNum;
	std::string itemName;
	double inStock;

	cout << "Enter the item's number: ";
	cin >> itemNum;
	cout << "Enter the item's name: ";
	cin.ignore();
	getline(cin, itemName);
	cout << "Enter the amount in stock: ";
	cin >> inStock;

	items.InsertNode(itemNum, itemName, inStock);

	cout << "Finished inserting item #" << itemNum << "'s data.\n";

	DisplayMenu(items);
}

// Update the amount of stock there is for an item (by item number).
void UpdateInStockAmount(ItemList items)
{
	double itemNum;
	double inStock;

	cout << "What item (number) should we change the in stock amount of? ";
	cin >> itemNum;
	cout << "How many are in stock now? ";
	cin >> inStock;

	items.ChangeInStock(itemNum, inStock);

	DisplayMenu(items);
}

// Delete a node based on the item's number
void DeleteListData(ItemList items)
{
	double itemNum;

	cout << "What item's (number) data should we delete? ";
	cin >> itemNum;

	items.DeleteNode(itemNum);

	DisplayMenu(items);
}

// Print the items that are in stock.
void PrintInStock(ItemList items)
{
	cout << "Current in stock items:\n";
	items.DisplayInStock();

	DisplayMenu(items);
}

// Write the linked list's data to the file.
void WriteListData(ItemList items)
{
	items.WriteItems();
	cout << "Finished writing file data.\n";

	DisplayMenu(items);
}