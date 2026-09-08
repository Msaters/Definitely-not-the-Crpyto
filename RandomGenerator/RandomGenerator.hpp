
#include <vector>
#include <string>
#include <random>

class RandomGenerator
{
private:
    const bool canTopicReccur_;
    std::random_device rd_;
    std::mt19937 generator_;

public:
    RandomGenerator(const bool canTopicReccur);

    std::vector<int> getRandomTopicNumbersForPlayer(
        const int wordsPerPlayer
        , const int cardsPerTeam);

    std::vector<std::string> getRandomCardTopicsForTeam(
        std::vector<std::string>& gameCardTopics
        , const int cardsPerTeam);
};
