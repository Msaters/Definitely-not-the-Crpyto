#pragma once

#include <vector>
#include <string>

class CardRepository
{
private:
    std::vector<std::string> gameCardTopics_;

public:
    void fetchGameCardTopcis(); 
    const std::vector<std::string>& getGameCardTopics() const;
    CardRepository();
};
