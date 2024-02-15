#include "Game.hpp"
#include <algorithm>
#include <cctype>
#include <cstring>
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
using std::strtok;
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
	cout << "\nHow many players?\n";
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
	for (unsigned int P = 0; P < Players.size(); P++) {
		if (P == 0) {
			cout << setfill(' ') << right << setw(5) << Players[0].GetName();
		} else {
			cout << " | " << setw(5) << Players[P].GetName();
		}
	}
	cout << endl;
	for (unsigned int U = 0; U < Players.size(); U++) {
		cout << "________";
	}
	cout << endl;
	for (unsigned int L = 0; L < Players.size(); L++) {
		if (L == 0) {
			cout << setw(5) << to_string(Players[0].GetLife());
		} else {
			cout << " | " << setw(5) << to_string(Players[L].GetLife());
		}
	}
	cout << endl;
}

int Game::GameTurn() {
	// checking for winners
	int loss_counter = 0;
	int first_living = -1;
	int living = 0;

	for (unsigned int W = 0; W < Players.size(); W++) {
		// increment the status counters
		if (Players[W].GetStatus() == 'L')
			loss_counter++;
		else {
			living++;
			first_living = W;
		}
		// if living is has multiple people break
		if (living > 1) break;
	}
	if (loss_counter == Players.size()) {  // everyone lost
		cout << "No one won.\n";
		return 0;
	}
	if (loss_counter == Players.size() - 1) {  // one person won
		cout << Players[first_living].GetName() << " won.\n";
		return 0;
	}

	// normal output per turn
	for (unsigned int P = 0; P < Players.size(); P++) {
		if (P == 0) {
			if (Players[P].GetStatus() == 'L') {
				cout << setfill(' ') << right << setw(5) << Players[P].GetStatus();
			} else {
				cout << setfill(' ') << right << setw(5)
				     << to_string(Players[P].GetLife());
			}
		}
		// all other players
		else {
			cout << " | ";
			if (Players[P].GetStatus() == 'L') {
				cout << setfill(' ') << right << setw(5) << Players[P].GetStatus();
			} else {
				cout << setfill(' ') << right << setw(5)
				     << to_string(Players[P].GetLife());
			}
		}
	}
	cout << endl;
	return 1;
}
// math functions

int Game::GetChanges() {
	string input;
	getline(cin, input, '\n');
	char delim = ' ';
	int spot = input.find(delim);
	vector<string> input_split;
	while (spot != -1) {
		string input_part = input.substr(0, spot);
		input_split.push_back(input_part);
		input.erase(input.begin(), input.begin() + spot + 1);
		spot = input.find(delim);
	}

	vector<int> changes_int;
	for (unsigned int P = 0; P < input_split.size(); P++) {
		if (!IsInt(input_split[P])) {
			cout << "Player " << P + 1
			     << " life changes are no numeric. \nPlease reinput life changes.";
			return -1;
		}
		changes_int.push_back(stoi(input_split[P]));
	}
	ChangeLives(changes_int);
	return 0;
}

void Game::ChangeLives(vector<int> LifeChanges) {
	for (unsigned int L = 0; L < Players.size(); L++) {
		Players[L].ChangeLife(LifeChanges[L]);
	}
}
