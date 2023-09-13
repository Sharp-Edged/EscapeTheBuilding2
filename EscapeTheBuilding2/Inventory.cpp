#include "Inventory.h"

Inventory::Inventory(int _width, int _height) {
	width = _width;
	height = _height;
	curItem = 0;
	items.push_back(std::make_shared<Lockpick>());
	items.push_back(std::make_shared<Lockpick>());
	items.push_back(std::make_shared<Lockpick>());
}

void Inventory::AddItem(std::shared_ptr<Item> item) {
	items.push_back(item);
}

void Inventory::RemoveItem(int index) {
	items.erase(items.begin() + index);
}

// Display the inventory in the top right corner of the screen
void Inventory::Display() {
	for (int x = WIDTH - width; x < WIDTH; x++) {
		for (int y = 0; y < height; y++) {
			terminal_put_ext(x, y, 0, 0, ' ');
			if (x == WIDTH - width) terminal_put_ext(x, y, 0, 0, 0x2551);
			if (y == height - 1) terminal_put_ext(x, y, 0, 0, 0x2550);
			if (x == WIDTH - width && y == height - 1) terminal_put_ext(x, y, 0, 0, 0x255A);
		}
	}

	for (int i = 0; i < (int)items.size(); i++) {
		if (i == curItem) terminal_color("orange");
		
		terminal_print(WIDTH - width + 2, i + 2, (std::to_string(i + 1) + ". " + items[i]->name).c_str());
		
		terminal_color("white");
	}
}

void Inventory::HandleKey(int key) {
	if (key == TK_UP || key == TK_W) {
		curItem = (curItem - 1 + items.size()) % items.size();
	}
	if (key == TK_DOWN || key == TK_S) {
		curItem = (curItem + 1) % items.size();
	}
}