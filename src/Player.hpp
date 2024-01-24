#pragma once

#include <iostream>

class Player
{
private:
		int Wins;
		int GamesPlayed;
		std::string Name;
public:
		Player();
		char* GetInput();
		void GetNameInput();
		void SetName(std::string);
		int GetRPSRandom();
		void SetPoints(bool);
};

