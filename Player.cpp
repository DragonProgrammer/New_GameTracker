#include "Player.hpp"
#include <string>
using std::string;
Player::Player() {
	Life = 0;
	Name = "   ";
	Status = 'I';
}

Player::Player(string N, int L) {
	Life = L;
	Name = N;
	Status = 'I';
}
// Takes in value from a game start function that determines type of game and
// from that picks starting life
void Player::SetLife(int L) { Life = L; }

void Player::SetName(string N) { Name = N; }

int Player::GetLife() { return Life; }

char Player::GetStatus() { return Status; }

string Player::GetName() { return Name; }
