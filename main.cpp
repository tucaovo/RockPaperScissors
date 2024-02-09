#include "iostream"
#include "vector"
#include "string"
#include<cstdlib> 

using namespace std;

int score{ 0 };

void gamePlayLoop();
void announceWinner(bool playerHasWon);

vector <string> Values{"rock", "paper", "scissors"};

int main() {
	std::cout << "Welcome to rock, paper, scissors" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "To pick rock, paper or scissors you need to write them down" << std::endl;
	gamePlayLoop();
	cout << " Your final score is " << score << endl;
}

void gamePlayLoop() {
	string playerVariant;
	int playerIntVariant{4};
	cin >> playerVariant;
	srand((unsigned)time(NULL));
	int random = rand() % 3;
	for (int i = 0; i < Values.size(); i++) {
		if (playerVariant == Values.at(i))
			playerIntVariant = i;
	}
	if (playerIntVariant == random) {
		cout << "Equals!" << endl;
		gamePlayLoop();
	}
	else if (playerIntVariant == 0) {
		if (random == 1) {
			announceWinner(0);
		}
		else if (random == 2)
		{
			announceWinner(1);
		}
	}
	else if(playerIntVariant == 1){
		if (random == 0) {
			announceWinner(1);
		}
		else if (random == 2)
		{
			announceWinner(0);
		}
	}
	else if (playerIntVariant == 2) {
		if (random == 0) {
			announceWinner(0);
		}
		else if (random == 1)
		{
			announceWinner(1);
		}
	}
}

void announceWinner(bool playerHasWon)
{
	if (playerHasWon) {
		cout << "You win !" << endl;
		score++;
	}
	else {
		cout << "You lose :( " << endl;
	}
	cout << "Do you want to play once again ? (respond yes or no) -> ";
	string playerResponse;
	cin >> playerResponse;
	if (playerResponse == "yes")
		gamePlayLoop();
}
