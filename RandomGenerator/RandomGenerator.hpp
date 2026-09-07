
#include <vector>

class RandomGenerator
{
private:
    const bool canTopicReccur_;

public:
    void getRandomTopicNumbersForPlayer(
        std::vector<int>& playerRandomNumbersVec
        , const int wordsPerPlayer);

    void getRandomCardTopicsForTeam(
        std::vector<std::string>& teamCardTopics
        , std::vector<std::string>& gameCardTopics
        , const int cardsPerTeam);
};
