#include "Player.hpp"
#include <string>
using std::string;
using std::to_string;
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

string Player::PlayerData() {
	string Output;
	Output = GetName() + " " + to_string(GetLife()) + "\n";
	return Output;
}
void Player::ChangeLife(int ChangeL) {
	if (GetStatus() == 'L') return;  // check if player has not lost already
	int life = GetLife();
	int new_life = Life + ChangeL;
	SetLife(new_life);
	if (new_life <= 0) {
		ChangeStatus('L');
	}
	return;
}

void Player::ChangeStatus(char ChangeS) { Status = ChangeS; }
