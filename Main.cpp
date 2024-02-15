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
	do {
		int r = Game1.GetChanges();
		while (r == -1) {
			r = Game1.GetChanges();
		}
	} while (Game1.GameTurn() == 1);

	return 0;
}
