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

	public:
		Game();
		Game(int NP);
// Size and NumP function supplied for general debug situations should the need arise
		int Size();

		int NumP();

		auto getPlayers(){return Players;};

		void SetNumP(int NP);

		void AddPlayer(string Name, int Life);
		void SetPlayer(string Name, int Life, int Position);


};

#endif
