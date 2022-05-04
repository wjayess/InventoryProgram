#include "LinkedList.h"
#include <fstream>

using namespace std;

// Appends a new node to the list with the given data.
void ItemList::AppendNode(double itemNum, string name, double stockNum)
{
	ListNode* newNode;
	ListNode* currentNode;

	newNode = new ListNode;
	newNode->itemNumber = itemNum;
	newNode->itemName = name;
	newNode->inStock = stockNum;
	newNode->next = nullptr;

	// If the head is non-existent, make it the new node.
	if (!head)
		head = newNode;
	else
	{
		// If it is, set the placeholder currentNode variable to the head node.
		currentNode = head;

		// Cycle through the nodes until we hit the end.
		while (currentNode->next)
			currentNode = currentNode->next;

		// Make the end node the new temporary node.
		currentNode->next = newNode;
	}
}

// Insert a new node within the list, sorted by itemNum.
void ItemList::InsertNode(double itemNum, string name, double stockNum)
{
	ListNode* newNode;
	ListNode* currentNode;
	ListNode* previousNode = nullptr;

	newNode = new ListNode;
	newNode->itemNumber = itemNum;
	newNode->itemName = name;
	newNode->inStock = stockNum;

	// If there is no head, make it the new node.
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		currentNode = head;
		previousNode = nullptr;

		// Skip to where the itemNum is greater than other nodes.
		while (currentNode != nullptr && currentNode->itemNumber < itemNum)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		// If the node is the first, place it before all others
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = currentNode;
		}
		else
		{
			// Otherwise, put it after the previousNode.
			previousNode->next = newNode;
			newNode->next = currentNode;
		}
	}
}

// Delete a node by it's number.
void ItemList::DeleteNode(double itemNum)
{
	ListNode* currentNode;
	ListNode* previousNode;
	previousNode = nullptr;

	// If there's no head, there's nothing to delete
	if (!head)
		return;

	// If the head is the itemNum, great! We found it. Now delete it, and move the next node up one.
	if (head->itemNumber == itemNum)
	{
		currentNode = head->next;
		delete head;
		head = currentNode;
	}
	else
	{
		// currentNode placement variable is at the head currently.
		currentNode = head;

		// While the placement variable isn't the number, go to the next node.
		while (currentNode != nullptr && currentNode->itemNumber != itemNum)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		// Finally, when the itemNum is equal to the one the user wants to delete, delete it.
		if (currentNode)
		{
			previousNode->next = currentNode->next;
			delete currentNode;
		}
	}
}

// Simple function, just display all the information of the nodes.
void ItemList::DisplayNodes() const
{
	ListNode* currentNode;
	currentNode = head;

	while (currentNode)
	{
		cout << currentNode->itemNumber << endl;
		cout << currentNode->itemName << endl;
		cout << currentNode->inStock << endl << endl;

		currentNode = currentNode->next;
	}
}

// Look through the nodes, find the user specified itemNum and change it's inStock to whatever the user specified.
void ItemList::ChangeInStock(double itemNum, double newInStock)
{
	ListNode* currentNode;
	currentNode = head;

	while (currentNode)
	{
		if (currentNode->itemNumber == itemNum)
		{
			currentNode->inStock = newInStock;

			break;
		}
		else
			currentNode = currentNode->next;
	}
}

// Another simple function. If the node has stock, display it.
void ItemList::DisplayInStock() const
{
	ListNode* currentNode;
	currentNode = head;

	while (currentNode)
	{
		if (currentNode->inStock > 0)
		{
			cout << currentNode->itemNumber << endl;
			cout << currentNode->itemName << endl;
			cout << currentNode->inStock << endl << endl;

			currentNode = currentNode->next;
		}
	}
}

void ItemList::ReadItems()
{
	std::ifstream inputFile;
	inputFile.open("D:\\CPPProjects\\InventoryProgram\\InventoryProgram\\Inventory.txt");
	std::string readPos;

	while (!inputFile.eof())
	{
		inputFile >> readPos;
		std::string itemName = readPos;

		inputFile >> readPos;
		double itemNum = std::strtod(readPos.c_str(), NULL);

		inputFile >> readPos;
		double inStock = std::strtod(readPos.c_str(), NULL);

		// I'm really bad at reading/writing files... So I'm just going to use this ugly fix for a weird bug.
		if (itemNum != std::strtod(itemName.c_str(), NULL) && inStock != std::strtod(itemName.c_str(), NULL))
		{
			AppendNode(itemNum, itemName, inStock);
		}
	}
}

// Write the list to a file.
void ItemList::WriteItems() const
{
	ListNode* currentNode;
	currentNode = head;

	ofstream outputFile;
	outputFile.open("D:\\CPPProjects\\InventoryProgram\\InventoryProgram\\Inventory.txt");

	while (currentNode)
	{
		outputFile << currentNode->itemName << " ";
		outputFile << currentNode->itemNumber << " ";
		outputFile << currentNode->inStock << " ";

		currentNode = currentNode->next;
	}
}