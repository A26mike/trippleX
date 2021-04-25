// cl trippleX.cpp /EHsc
#include <iostream>
#include <ctime>
#include <cstdlib>

void PrintIntroduction(int Difficulty)
{
    if (Difficulty == 1)
    {
        std::cout << R"(
                                                            
                                                _=====_                               _=====_
                                                / _____ \                             / _____ \
                                            +.-'_____'-.---------------------------.-'_____'-.+
                                            /   |     |  '.        S O N Y        .'  |  _  |   \
                                            / ___| /|\ |___ \                     / ___| /_\ |___ \
                                            / |      |      | ;  __           _   ; | _         _ | ;
                                            | | <---   ---> | | |__|         |_:> | ||_|       (_)| |
                                            | |___   |   ___| ;SELECT       START ; |___       ___| ;
                                            |\    | \|/ |    /  _     ___      _   \    | (X) |    /|
                                            | \   |_____|  .','" "', |___|  ,'" "', '.  |_____|  .' |
                                            |  '-.______.-' /       \ANALOG/       \  '-._____.-'   |
                                            |               |       |------|       |                |
                                            |              /\       /      \       /\               |
                                            |             /  '.___.'        '.___.'  \              |
                                            |            /                            \             |
                                            \          /                              \           /
                                            \________/                                \_________/
                                                               

 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.       .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |     | .--------------. |
| |  _________   | || |  _______     | || |     _____    | || |   ______     | || |   ______     | || |   _____      | || |  _________   | |     | |  ____  ____  | |
| | |  _   _  |  | || | |_   __ \    | || |    |_   _|   | || |  |_   __ \   | || |  |_   __ \   | || |  |_   _|     | || | |_   ___  |  | |     | | |_  _||_  _| | |
| | |_/ | | \_|  | || |   | |__) |   | || |      | |     | || |    | |__) |  | || |    | |__) |  | || |    | |       | || |   | |_  \_|  | |     | |   \ \  / /   | |
| |     | |      | || |   |  __ /    | || |      | |     | || |    |  ___/   | || |    |  ___/   | || |    | |   _   | || |   |  _|  _   | |     | |    > `' <    | |
| |    _| |_     | || |  _| |  \ \_  | || |     _| |_    | || |   _| |_      | || |   _| |_      | || |   _| |__/ |  | || |  _| |___/ |  | |     | |  _/ /'`\ \_  | |
| |   |_____|    | || | |____| |___| | || |    |_____|   | || |  |_____|     | || |  |_____|     | || |  |________|  | || | |_________|  | |     | | |____||____| | |
| |              | || |              | || |              | || |              | || |              | || |              | || |              | |     | |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |     | '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'       '----------------' 
        
        
        
        )";
    }

    std::cout << "\nYou are a secret agent breaking into LEVEL " << Difficulty << " server room...\n";
    std::cout << "Your SuperHacker 2000 tells you the following information...\n";
}

int GetRandomNum(int start, int end){
    int results = start + (rand() % end);
    return results;
}

bool PlayGame(int Difficulty)
{
    //random number 1 - Difficulty
    const int CodeA = GetRandomNum(1, Difficulty);
    const int CodeB = GetRandomNum(1 , Difficulty);
    const int CodeC = GetRandomNum(1 , Difficulty);

    PrintIntroduction(Difficulty);
    const int CodeProduct = CodeA * CodeB * CodeC;
    const int CodeSum = CodeA + CodeB + CodeC;

    std::cout << "\n+ There are three numbers in the code\n";
    std::cout << "+ The codes multiply to give " << CodeProduct << "\n";
    std::cout << "+ The codes add-up to " << CodeSum << "\n";

    std::cout << "\nEnter the three code numbers followed by x \n";

    int GuessA, GuessB, GuessC;
    int GuessSum, GuessProduct;

    //get player guess
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
    {
        std::cout << "You won\n\n";

        return true;
    }

    else
    {
        std::cout << "You lost\n\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    bool EndGame = false;
    while (!EndGame)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        // stop infinate loop if char is entered
        std::cin.clear();  // clears errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        else
        {
            EndGame = true;
            std::cout << "\nCongratulations you made it to level " << LevelDifficulty << std::endl;
            std::cout << "Press any key to quit" <<  std::endl;
            std::cin.ignore();  
        }
    }
    return 0;
}