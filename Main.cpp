#include <iostream>
#include <string>
#include "Player.hpp"
using std::cout;
using std::endl;
int main() {
	Player Player1, Player2;
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

	return 0;
}
