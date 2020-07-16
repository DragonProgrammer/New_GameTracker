#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#include "Validate.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isalpha;
using std::remove_if;
using std::stoi;
using std::to_string;
using std::vector;
using Validate::IsInt;
using Validate::IsPositive;

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

// Should overwrite a player in Players with a different Player
void Game::SetPlayer(string Name, int Life, int Position) {
	Players[Position] = Player(Name, Life);
}
// Adds a player to the end
void Game::AddPlayer(string Name, int Life) {
	Players.push_back(Player(Name, Life));
}

// debug
string Game::PlayersData() {
	string Output;
	for (auto i : Players) {
		Output = Output + i.PlayerData();
	}
	return Output;
}
// Start of the interactive part of program
void Game::InputPlayNum() {
	cout << "\nnHow many players?\n";
	while (1) {
		string input;  // leading white space is ignored
		getline(cin, input, '\n');
		if (cin.fail()) {
			cout << "No more input\n";
			return;
		}
		cout << input << endl;
		//		if (IsPositive(input)) {
		//			SetNumP(stoi(input));
		//			break;
	}
	// cin.ignore(80, '\n');
	// cin.clear();
	cout << "Please input a number greater then 0\n";
}
}
void Game::InputPlayers() {
	vector<string> Names;
	int num = this->NumP();
	int PlayerNum = 1;
	while (Names.size() < num) {
		cout << "Please enter the 3 letter initials of Player " +
		            to_string(PlayerNum) + ":\n";
		string Init;
		getline(cin, Init, '\n');
		string Init2 = Init.substr(0, 5);
		cout << Init2 << endl;
		Init2.erase(remove_if(Init2.begin(), Init2.end(),
		                      [](unsigned char c) { return !isalpha(c); }),
		            Init2.end());
		cout << Init2 << endl;

		if (IsInt(Init2)) {
			cout << "Input must be non-numeric.\n";
			continue;
		}
		Names.push_back(Init2);
		PlayerNum++;
	}
}
int Game::Size() { return Players.size(); }
int Game::NumP() { return NumPlayers; }
