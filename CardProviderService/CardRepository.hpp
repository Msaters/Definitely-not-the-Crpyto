#pragma once

#include <vector>
#include <string>

class CardRepository
{
private:
    std::vector<std::string> gameCardTopics;

public:
    void fetchGameCardTopcis(); 
    std::vector<std::string>& getGameCardTopics();

};
