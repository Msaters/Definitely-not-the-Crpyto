#include "CardRepository.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

void CardRepository::fetchGameCardTopcis()
{   
    std::ifstream file("CardProviderService/cardTopics.csv"); // later use enviroment variable

    if (!file.is_open()) {
        std::cerr << "Couldn't open the csv file!\n";
        // later I would like to throw error here
        return;
    }

    std::string line;
    if (!std::getline(file, line))
    {
        std::cerr << "Csv File is empty!\n";
        return;
    }

    try
    {
        const int deckSize = std::stoi(line);
        gameCardTopics_.clear();
        gameCardTopics_.reserve(deckSize);

        int i = 0;
        while (std::getline(file, line))
        {
            gameCardTopics_.push_back(line);
            std::cout << "gameCardTopic: " << line << " i: " << i << std::endl;
            i++;
        }
    }
    catch (const std::invalid_argument& exception)
    {
        std::cerr << "Invalid deck, first line of deck have to be deck size number: "
                << exception.what() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Other exception: " << e.what() << '\n';
    }
    
}

const std::vector<std::string>& CardRepository::getGameCardTopics() const
{
    return gameCardTopics_;
}

CardRepository::CardRepository()
{
    fetchGameCardTopcis();
}