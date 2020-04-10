// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty) 
{
	std::cout << "You are breaking into a level " << Difficulty;
	std::cout << " server room. Enter the correct code or parish";
}

bool PlayGame(int Difficulty) 
{
	
	PrintIntro(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;


	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << std::endl;
	std::cout << "The codes add up to: " << CodeSum << std::endl;
	std::cout << "The product of the codes is: " << CodeProduct << std::endl;

	int PlayerGuessA, PlayerGuessB, PlayerGuessC;
	int GuessSum, GuessProduct;

	std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

	GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;
	GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
	{
		std::cout << "\nYou da winner!\n";
		return true;
	}
	else {
		std::cout << "You did not enter the correct code\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	int MaxDifficulty = 10;

	while (LevelDifficulty <= MaxDifficulty) 
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	
	return 0;
}
