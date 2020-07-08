#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Validate.cpp"
using std::cin;
using std::cout;
using std::vector;
using Validate::IsPositive;
Game::Game() {
	NumPlayers = 1;
	while (Players.size() < NumPlayers) {
		Players.push_back(Player());
	}
}

Game::Game(int NP) {
	SetNumP(NP);
	while (Players.size() < NumPlayers) {
		Players.push_back(Player());
	}
}

void Game::SetNumP(int NP) { NumPlayers = NP; }

// Should overwrite a player in Players with a different Player
void Game::SetPlayer(string Name, int Life, int Position) {
	Players[Position] = Player(Name, Life);
}
// Adds a player to the end
void Game::AddPlayer(string Name, int Life) {
	Players.push_back(Player(Name, Life));
}

// debug
string Game::PlayersData() {
	string Output;
	for (auto i : Players) {
		Output = Output + i.PlayerData();
	}
	return Output;
}
// Start of the interactive part of program
void Game::InputPlayNum() {
	cout << "How many players?\n";

	Validate::IsPositive();
	//	SetNumP(Validate.IsPositive());
}

int Game::Size() { return Players.size(); }
int Game::NumP() { return NumPlayers; }
