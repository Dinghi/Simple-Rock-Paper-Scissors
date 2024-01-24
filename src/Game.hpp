#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Player.hpp"
enum RPSStates {
		Rock = 0,
		Paper,
		Scissors
};
enum GameWinState {
		win = 0,
		lose,
		tie
};
class Game
{
private:
		bool Running;
		const std::vector<std::string> menuList = { "Play", "Restart", "Exit" };
		Player player;
public:
		const std::vector<std::string> objList = { "Rock", "Paper", "Scissors" };
		const std::vector<std::string> gameWinStateStr = { "Win", "Lose", "Tie" };
		Game();
		Game(bool);
		~Game();
		void SetGameState(bool);
		void PrintGameMenu();
		void PrintChoseRPS();
		void ExecuteChoice(int);
		void Play();
		void StartGame();
		GameWinState PlayerWins(int, int);
		Player* GetPlayer();
};

