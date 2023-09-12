#include "Common.h"

std::ostream& operator<<(std::ostream& out, const Point& point) {
	out << "(" << point.x << ", " << point.y << ")";
	return out;
}