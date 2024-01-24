#pragma once

#include <iostream>

enum PlayerState {
		winner = 0,
		loses,
		ties,
		gamesPlayed,
};

class Player
{
private:
		int States[4];
		int GamesPlayed;
		std::string Name;
public:
		Player();
		void _Init();
		char* GetInput();
		void GetNameInput();
		void SetName(std::string);
		int GetRPSRandom();
		int GetStates(PlayerState);
		int GetGamesPlayed();
		void SetPoints(PlayerState);
};

