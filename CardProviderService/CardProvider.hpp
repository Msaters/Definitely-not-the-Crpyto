#include "RandomGenerator.hpp"
#include "CardRepository.hpp"

#include <vector>
#include <string>

class CardProvider 
{
private:
    const CardRepository cardRepository_;
    const std::vector<std::string>& gameCardTopics_;
    
public:
    CardProvider() 
    : gameCardTopics_(cardRepository_.getGameCardTopics())
    {
        ;
    }
};
