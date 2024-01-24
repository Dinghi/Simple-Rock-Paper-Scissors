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
		void _Init();
		char* GetInput();
		void GetNameInput();
		void SetName(std::string);
		int GetRPSRandom();
		int GetWins();
		int GetGamesPlayed();
		void SetPoints(bool);
};

