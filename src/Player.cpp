#include<iostream>
#include<iomanip>

#include "Player.hpp"

Player::Player() {  }
void Player::_Init() { States[PlayerState::winner] = 0; States[PlayerState::loses] = 0; States[PlayerState::ties] = 0; States[PlayerState::gamesPlayed] = 0; Name = "New Player"; }

void Player::SetPoints(PlayerState state) {
		States[state]++;
		States[PlayerState::gamesPlayed]++;
}
void Player::SetName(std::string n) { Name = n; }
char* Player::GetInput() {
		const size_t BUFFER_SIZE = 1024;
		char input[BUFFER_SIZE];
		std::cin >> std::setw(BUFFER_SIZE) >> input;
		return input;
}
void Player::GetNameInput() {
		std::cout << "Give me a name: ";
		std::string name;
		std::cin >> name;
		SetName(name);
};
int Player::GetRPSRandom() {
		srand(time(NULL));
		return rand() % 3;
}
int Player::GetStates(PlayerState state) { return States[state]; }
int Player::GetGamesPlayed() { return GamesPlayed; }