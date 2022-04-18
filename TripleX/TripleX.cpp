#include <iostream>
#include <ctime>

void MainIntroduction()
{
	std::cout << "Enter the correct codes to bypass the gates on each security level...\n";
}

void LevelIntroduction(int Difficulty)
{
	std::cout << "\n\nYou see a large steel gate with a metal keypad...\n";
	std::cout << "This keypad has a security level of " << Difficulty << ".\n\n";
}

bool PlayGame(int Difficulty, int MaxDifficulty)
{
	LevelIntroduction(Difficulty);

	const int KeyPadCodeA = rand() % Difficulty + Difficulty;
	const int KeyPadCodeB = rand() % Difficulty + Difficulty;
	const int KeyPadCodeC = rand() % Difficulty + Difficulty;

	const int KeyPadSum = KeyPadCodeA + KeyPadCodeB + KeyPadCodeC;
	const int KeyPadProduct = KeyPadCodeA * KeyPadCodeB * KeyPadCodeC;

	std::cout << "There are 3 numbers in the code.\n";
	std::cout << "The keypad code add up to: " << KeyPadSum << "\n";
	std::cout << "The keypad code multiply to: " << KeyPadProduct << "\n";

	int KeyPadGuessA, KeyPadGuessB, KeyPadGuessC;
	std::cin >> KeyPadGuessA >> KeyPadGuessB >> KeyPadGuessC;

	const int KeyPadGuessSum = KeyPadGuessA + KeyPadGuessB + KeyPadGuessC;
	const int KeyPadGuessProduct = KeyPadGuessA * KeyPadGuessB * KeyPadGuessC;

	if (KeyPadGuessSum == KeyPadSum && KeyPadGuessProduct == KeyPadProduct)
	{
		std::cout << "\nSuccess! The code you entered was correct!\n";
		if (MaxDifficulty == Difficulty)
		{
			std::cout << "You unlocked the final gate, deactivated the switch, and saved the world!\n";
		}
		return true;
	}
	else
	{
		std::cout << "\nFailed! The code you entered was incorrect!\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	const int MaxLevelDifficulty = 5;

	MainIntroduction();

	while (LevelDifficulty <= MaxLevelDifficulty) //Loops all levels until the game is complete
	{
		bool LevelComplete = PlayGame(LevelDifficulty, MaxLevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (LevelComplete)
		{
			++LevelDifficulty;
		}
	}

	return 1;
}
