#ifndef Player
#define Player
#include <string>
using std::string;
class Player {
	private:
	int Life;
	string Name;
	
	char Status;
		// Status are: L = lose, W = Win, I = in game
	
	public:
	Player();
	void SetLife(int L);
	void SetName(string N);
	void ChangeLife(int ChangeL);
	void ChangeStatus(char ChangeC);
	void CheckLife();
	int GetLife();
	char GetStatus();
	string GetName();
};

#endif
