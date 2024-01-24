#include "Game.hpp"

Game::Game() : Running{ 0 } { }
Game::Game(bool state) { Running = state; }

Game::~Game() { }

void Game::SetGameState(bool state) { Running = state; }
void Game::PrintChoseRPS() {
		std::cout << "Pick one: \n";
		for (int i = 0; i < objList.size(); i++) {
				std::cout << i + 1 << ") " << objList[i] << "\n";
		}
}
void Game::PrintGameMenu() {
		std::cout << "What do you want to do? \n";
		for (int i = 0; i < menuList.size(); i++) {
				std::cout << i + 1 << ") " << menuList[i] << "\n";
		}
}
void Game::ExecuteChoice(int choice) {
		switch (choice)
		{
		case 1:
				StartGame();
				break;
		case 2:
				Play();
		case 3:
				SetGameState(false);
				break;
		default:
				std::cout << "Command not recognized";
				break;
		}
}
Player* Game::GetPlayer() {
		return &player;
}
void Game::Play() {
		SetGameState(true);
		player.GetNameInput();
		PrintGameMenu();
		ExecuteChoice(atoi(player.GetInput()));
}
GameWinState Game::PlayerWins(int playerChoice, int enemyChoice) {
		if (playerChoice == RPSStates::Rock && enemyChoice == RPSStates::Paper) { return GameWinState::lose; }
		else if (playerChoice == RPSStates::Paper && enemyChoice == RPSStates::Rock) { return GameWinState::win; }
		if (playerChoice == RPSStates::Scissors && enemyChoice == RPSStates::Paper) { return GameWinState::win; }
		else if (playerChoice == RPSStates::Paper && enemyChoice == RPSStates::Scissors) { return GameWinState::lose; }
		if (playerChoice == RPSStates::Rock && enemyChoice == RPSStates::Scissors) { return GameWinState::win; }
		else if (playerChoice == RPSStates::Scissors && enemyChoice == RPSStates::Rock) { return GameWinState::lose; }
		return GameWinState::tie;
}
void Game::StartGame() {
		while (Running)
		{
				PrintChoseRPS();
				int playerChoice = atoi(player.GetInput()) - 1;
				int enemyChoice = player.GetRPSRandom();
				GameWinState winState = PlayerWins(playerChoice, enemyChoice);
				std::cout << "Player: " << objList[playerChoice] << " enemy: " << objList[enemyChoice] << " Result: " << gameWinStateStr[winState] << "!\n";
				player.SetPoints(winState == GameWinState::win);
				PrintGameMenu();
				ExecuteChoice(atoi(player.GetInput()));
		}
}
