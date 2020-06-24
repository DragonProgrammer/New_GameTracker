#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using std::cout;
using std::endl;
int main() {
	Game Game1, Game2(2);
	Player Player1, Player2, Player3("Lizzy", 40);
	cout << Player1.GetLife() << endl;
	cout << Player1.GetName() << endl;
	cout << Player2.GetLife() << endl;
	cout << Player2.GetName() << endl;

	Player1.SetName("Mike");
	Player1.SetLife(40);
	Player2.SetName("Murry");
	Player2.SetLife(40);

	cout << Player1.GetLife() << endl;
	cout << Player1.GetName() << endl;
	cout << Player2.GetLife() << endl;
	cout << Player2.GetName() << endl;

	cout << Game1.Size() << endl;
	cout << Game2.Size();

	return 0;
}
