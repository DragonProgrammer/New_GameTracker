#include "Game.hpp"
#include <vector>
using std::vector;

Game::Game() {
	NumPlayers = 1;
	while (Players.size() < NumPlayers) {
		Players.push_back(Player());
	}
}

int Game::Size() { return Players.size(); }
int Game::NumP() { return NumPlayers; }
