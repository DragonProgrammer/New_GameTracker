#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"

//#include "Validate.hpp"
using std::cout;
using std::endl;
int main() {
	Game Game1;

	Game1.InputPlayNum();
	cout << Game1.NumP();
	vector<string> P = Game1.GetInitials();
	Game1.SelectGameType();
	Game1.InputPlayers(P);
	Game1.GameHeader();
	return 0;
}
