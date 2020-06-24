#include "Game.hpp"
#include <vector>
using std::vector;

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

int Game::Size() { return Players.size(); }
int Game::NumP() { return NumPlayers; }
