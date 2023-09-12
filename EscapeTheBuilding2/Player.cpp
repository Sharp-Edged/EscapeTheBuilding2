#include "Player.h"

Player::Player(int _health, int _x, int _y) {
	health = _health;
	coords.x = _x;
	coords.y = _y;
}

int Player::GetX() {
	return coords.x;
}
int Player::GetY() {
	return coords.y;
}
Point Player::GetCoords() {
	return coords;
}
void Player::SetX(int x) {
	coords.x = x;
}
void Player::SetY(int y) {
	coords.y = y;
}
void Player::SetCoords(Point _coords) {
	coords = _coords;
}