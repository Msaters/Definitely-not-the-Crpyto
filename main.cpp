#include "CardProviderService/CardProvider.hpp"

#include <windows.h>
#include <iostream>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "STARTED" << std::endl;

    // settings 
    const int teamsCount = 2, cardsPerTeam = 4, wordsPerPlayer = 3;
    const bool canTopicReccur = false;

    const CardProvider cardProvider;
    return 0;
}