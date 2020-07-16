#include "Game.hpp"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include "Validate.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::isalpha;
using std::left;
using std::remove_if;
using std::right;
using std::setfill;
using std::setw;
using std::stoi;
using std::to_string;
using std::vector;
using Validate::Is3Chars;
using Validate::IsInRange;
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
		//	cout << input << endl;
		if (IsPositive(input)) {
			SetNumP(stoi(input));
			break;
		}
		// cin.ignore(80, '\n');
		// cin.clear();
		cout << "Please input a number greater then 0\n";
	}
}
void Game::InputPlayers(vector<string> P) {
	int L = InitialLife();
	for (auto i : P) {
		// cout << i;
		AddPlayer(i, L);
	}
	Players.erase(Players.begin());
}

vector<string> Game::GetInitials() {
	vector<string> Names;
	int num = this->NumP();
	int PlayerNum = 1;
	while ((static_cast<signed int>(Names.size())) < num) {
		cout << "Please enter the 3 letter initials of Player " +
		            to_string(PlayerNum) + ":\n";
		string Init;
		getline(cin, Init, '\n');
		string Init2 = Init.substr(0, 5);
		//	cout << Init2 << endl;
		Init2.erase(remove_if(Init2.begin(), Init2.end(),
		                      [](unsigned char c) { return !isalpha(c); }),
		            Init2.end());
		//	cout << Init2 << endl;

		if (!Is3Chars(Init2)) {
			continue;
		}
		Names.push_back(Init2);
		PlayerNum++;
	}
	return Names;
}
void Game::SelectGameType() {
	cout << "Input the number of the type of game played: \n"
	     << "1) 60 card, 20 Life \n"
	     << "2) 100 card, 40 Life \n"
	     << "3) 40 card, 20 Life \n"
	     << "4) 60 card, 30 Life\n";
	string Game;
	getline(cin, Game, '\n');
	if (cin.fail()) {
		cout << "no more inputs\n";
		exit(0);
	}
	if (IsInRange(Game)) {
		int C = stoi(Game);
		switch (C) {
			case 1:
				SetGameData(20);
				break;
			case 2:
				SetGameData(40);
				break;
			case 3:
				SetGameData(20);
				break;
			case 4:
				SetGameData(30);
				break;
			default:
				cout << "How did this happen?\n";
				break;
		}
	} else {
		return SelectGameType();
	}
}
void Game::SetGameData(int L) { StartLife = L; }
int Game::Size() { return Players.size(); }
int Game::NumP() { return NumPlayers; }
int Game::InitialLife() { return StartLife; }
void Game::SetGameType(int T) { GameType = T; }

// format functions
//
void Game::GameHeader() {
	for (int P = 0; P < Players.size(); P++) {
		if (P == 0) {
			cout << setfill(' ') << right << setw(5) << Players[0].GetName();
		} else {
			cout << " | " << setw(5) << Players[P].GetName();
		}
	}
	cout << endl;
	for (int U = 0; U < Players.size(); U++) {
		cout << "________";
	}
	cout << endl;
	for (int L = 0; L < Players.size(); L++) {
		if (L == 0) {
			cout << setw(5) << to_string(Players[0].GetLife());
		} else {
			cout << " | " << setw(5) << to_string(Players[L].GetLife());
		}
	}
	cout << endl;
}
