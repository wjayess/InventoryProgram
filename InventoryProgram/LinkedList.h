#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

// Linked list class
class ItemList
{
private:
	// Data structure
	struct ListNode
	{
		double itemNumber = 0;
		std::string itemName;
		double inStock = 0;
		// "next" for the next node's pointer
		ListNode* next = nullptr;
	};

	// Head meaning the first node
	ListNode* head;

public:
	// Inline constructor to set the head as a nullptr.
	ItemList() { head = nullptr; };

	// Member function prototypes
	// Mutators
	void AppendNode(double, std::string, double);
	void InsertNode(double, std::string, double);
	void DeleteNode(double);
	void ChangeInStock(double, double);
	void ReadItems();

	// Accessors
	void DisplayNodes() const;
	void DisplayInStock() const;
	void WriteItems() const;
};

#endif