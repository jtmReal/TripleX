#include <iostream>
#include <ctime>

void PrintIntroduction(int DifficultyLevel){
    std::cout << "Hello, World!";//std is a namespace, cout outputs stuff to terminal
    std::cout << std::endl;//ends line
    std::cout << "This is my first time using C++" << std:: endl;
    std::cout << "Lets play a little game" << std:: endl;
    std::cout << "You are a hacker breaking into a level " << DifficultyLevel << " server" << std:: endl;
}

bool PlayGame(int Difficulty)//Returns bool value
{
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;//const makes sure the values never change
    const int CodeB = rand() % Difficulty + Difficulty;//rand() %4 Makes it pick a random number from 0 up to 3
    const int CodeC = rand() % Difficulty + Difficulty;//added Difficulty again so for for example  it goes from 1 to 2-3 to 3-5 to 4-7, etc.

    //a = 7;//Assigning new value to a, cant assign new values to constants

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code" << std::endl;
    std:: cout << "The numbers add up to: " << CodeSum << std:: endl;//Prints sum then ends line
    std:: cout << "The product of these numbers is: " << CodeProduct << std::endl;//Prints product

    //Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;// cin with >> is getting players input

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << std::endl << "Your guess was: " << GuessA << GuessB << GuessC;

    //Check if players Guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCongrats you win!\n\n";// I can use \n to skip to next line too
        return true;
    }
    else
    {
        std::cout << "\nYou lose!\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));//Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    while (LevelDifficulty <= MaxDifficulty)//Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout<< "Congrats you've made it through all 3 Levels!!";
    return 0; 
    
}

/*
Additional Stuff for me to know

<< is the insertion operator

*/