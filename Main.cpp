#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using std::cout;
using std::endl;
int main() {
	Game Game1, Game2();
	Player Player1, Player2, Player3("Lizzy", 40);

	Player1.SetName("Mike");
	Player1.SetLife(40);
	Player2.SetName("Murry");
	Player2.SetLife(40);

	Game2.Players[0] = Player1;
	Game2.Players[1] = Player2;

	cout << Player3.GetLife() << endl;
	cout << Player3.GetName() << endl;

	cout << Game1.Size() << endl;
	cout << Game2.Size() << endl;

	Game2.Players[2] = Player3;

	cout << Game2.Size();
	return 0;
}
