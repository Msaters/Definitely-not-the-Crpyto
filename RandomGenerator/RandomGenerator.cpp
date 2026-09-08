#include "RandomGenerator.hpp"

#include <algorithm>
#include <numeric>
#include <iostream>


RandomGenerator::RandomGenerator(const bool canTopicReccur)
    : canTopicReccur_(canTopicReccur)
    , generator_(rd_())
{  
    ;
}

std::vector<int> RandomGenerator::getRandomTopicNumbersForPlayer(
    const int wordsPerPlayer
    , const int cardsPerTeam)
{
    std::vector<int> numbers(cardsPerTeam);
    std::iota(numbers.begin(), numbers.end(), 1);
    std::shuffle(numbers.begin(), numbers.end(), generator_);

    numbers.resize(wordsPerPlayer);
    return numbers;
}

std::vector<std::string> RandomGenerator::getRandomCardTopicsForTeam(
    std::vector<std::string>& gameCardTopics
    , const int cardsPerTeam)
{
    const int gameCardTopicsSize = gameCardTopics.size();
    if (gameCardTopicsSize < cardsPerTeam)
    {
        // to do change std::cerr to throwing error mechanism
        std::cerr << "gameCardTopicsSize is less than cardsPerTeam, deck needs refetch" << std::endl;
        return {};
    }

    std::vector<int> numbers(gameCardTopicsSize);
    std::iota(numbers.begin(), numbers.end(), 0);
    std::shuffle(numbers.begin(), numbers.end(), generator_);

    std::vector<std::string> teamCardTopics(cardsPerTeam);
    for (int i = 0; i < cardsPerTeam; i++)
    {
        teamCardTopics.push_back(gameCardTopics[numbers[i]]);
    }

    if (!canTopicReccur_)
    {
        std::sort(numbers.begin(), numbers.begin() + cardsPerTeam);
        for (int i = cardsPerTeam - 1; i >= 0; i--)
        {
            std::swap(gameCardTopics[numbers[i]], gameCardTopics.back());
            gameCardTopics.pop_back();
        }
    }

    return teamCardTopics;
}