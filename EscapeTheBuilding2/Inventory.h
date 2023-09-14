#pragma once
#include "Common.h"
#include "Items.h"
#include <map>

class Inventory {
private:
	vector<std::shared_ptr<Item>> items;
	int width;
	int height;
	int curItem;
public:
	Inventory(int _width, int _height);
	void AddItem(std::shared_ptr<Item> item);
	void RemoveItem(int index);
	void Display();
	void HandleKey(int key);
};