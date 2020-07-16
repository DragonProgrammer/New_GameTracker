#include "Format.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
using std::cout;
void Format::SetGame(Game G) { ToFormat = G; }
void Format::GameHeader() {
	vector<Player> P = ToFormat.getPlayers();
	cout << P[0].Name;
}
