#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
//#include "Validate.hpp"
using std::cout;
using std::endl;
int main() {
	Game Game1, Game2(2);
	Player Player1, Player2, Player3("Lizzy", 40);

	Game2.SetPlayer("Mike", 40, 0);
	Game2.SetPlayer("Murry", 40, 1);

	cout << Game2.getPlayers()[0].GetName() << endl;
	cout << Game2.getPlayers()[1].GetName() << endl;

	cout << Game1.Size() << endl;
	cout << Game2.Size() << endl;
	Game2.AddPlayer("Llama", 40);
	cout << Game2.PlayersData();
	cout << Game2.Size();
	Game1.InputPlayNum();
	Game1.InputPlayNum();
	Game1.InputPlayNum();
	Game1.InputPlayNum();
	return 0;
}
