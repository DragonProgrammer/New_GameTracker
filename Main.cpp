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
	vector<string> P = Game1.GetPlayers();
	Game1.SelectGameType();
	return 0;
}
