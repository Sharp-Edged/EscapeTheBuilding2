#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "BearLibTerminal.h"

#define WIDTH 80
#define HEIGHT 25

using std::cout, std::string, std::vector, std::endl;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};