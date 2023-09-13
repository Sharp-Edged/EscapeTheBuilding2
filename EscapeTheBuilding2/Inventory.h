#pragma once
#include "Common.h"
#include "Item.h"
#include <map>

class Inventory {
private:
	vector<std::shared_ptr<Item>> items;
	int width = 10;
	int height = 10;
public:
	Inventory(int _width, int _height);
	void AddItem(std::shared_ptr<Item> item);
	void RemoveItem(int index);
	void Display();
};