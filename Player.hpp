#include <string>
using std::string;
#ifndef Player_h
#define Player_h
class Player {
	private:
	int Life;
	string Name;
	
	char Status;
		// Status are: L = lose, W = Win, I = in game
	
	public:
	Player();
	Player(string N, int L);
	void SetLife(int L);
	void SetName(string N);
	void ChangeLife(int ChangeL);
	void ChangeStatus(char ChangeS);
	void CheckLife();
	int GetLife();
	char GetStatus();
	string GetName();
	string PlayerData();
};

#endif
