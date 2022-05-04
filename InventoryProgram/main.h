#ifndef MAIN_H
#define MAIN_H
#include "LinkedList.h"

// Function prototypes
void DisplayMenu(ItemList);
void MenuThink(char, ItemList);
void ReadListData(ItemList);
void InsertListData(ItemList);
void UpdateInStockAmount(ItemList);
void DeleteListData(ItemList);
void PrintInStock(ItemList);
void WriteListData(ItemList);

#endif