#include "Player.hpp"

#include<iostream>
#include<iomanip>


Player::Player() {  }
void Player::_Init() { Wins = 0; GamesPlayed = 0; Name = "New Player"; }

void Player::SetPoints(bool winner) { if (winner) Wins++; GamesPlayed++; }
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
int Player::GetWins() { return Wins; }
int Player::GetGamesPlayed() { return GamesPlayed; }