#include "Player.h"

Player::Player(int _Health) {
	Health = _Health;
	Coords[0] = 10;
	Coords[1] = 10;
}

int Player::GetX() {
	return Coords[0];
}
int Player::GetY() {
	return Coords[1];
}
std::array<int, 2> Player::GetCoords() {
	return Coords;
}
void Player::SetX(int x) {
	Coords[0] = x;
}
void Player::SetY(int y) {
	Coords[1] = y;
}
void Player::SetCoords(std::array<int, 2> _Coords) {
	Coords = _Coords;
}