#ifndef Game_h
#define Game_h
#include "Player.hpp"
#include <vector>
using std::vector;
using std::string;
class Game{
	private:
		unsigned int NumPlayers;  //probably bad form but gets rid of unsigned to signed comparison
		vector<Player> Players;
		int GameType; // 1 = 60 card/ 20 life; 2 = commander, 3 = 60 cards/ 30 life (brawl)
		int StartLife;
	public:
		Game();
		Game(int NP);
// Size and NumP function supplied for general debug situations should the need arise
		int Size();

		int NumP();
		

		auto getPlayers(){return Players;};
		string PlayersData();
		void SetNumP(int NP);
		void SetGameData(int L);
		void SetGameType(int T);
		void AddPlayer(string Name, int Life);
		void SetPlayer(string Name, int Life, int Position);
		void InputPlayNum();
		void InputPlayers(vector<string> P);
		vector<string> GetPlayers();
		void SelectGameType();
};

#endif
