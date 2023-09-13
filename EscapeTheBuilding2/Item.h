#pragma once
#include "Common.h"

struct Item {
	string name;
	string description;
	bool equipable = false;

	Item() {}

	Item(const Item&) = default;
	Item(Item&&) = default;
	Item& operator=(const Item&) = default;
	Item& operator=(Item&&) = default;
	virtual ~Item() = default;

	virtual void UseItem() = 0;
};

struct Lockpick : Item {
	Lockpick() {
		name = "Lockpick";
		description = "Does things";
		equipable = true;
	};

	void UseItem() {
		cout << "yuuup\n";
	}
};