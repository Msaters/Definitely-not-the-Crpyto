#include "../RandomGenerator/RandomGenerator.hpp"
#include "../CardProviderService/CardRepository.hpp"
#include "../InputOutputLib/outputHelpers.hpp"


bool checkNumberOfTopicsIngetRandomTopicNumbersForPlayer(
    const int wordsPerPlayer,
    const int cardsPerTeam)
{
    RandomGenerator randomGenerator(true);
    std::vector<int> randomVec = std::move(
        randomGenerator.getRandomTopicNumbersForPlayer(
            wordsPerPlayer
            , cardsPerTeam));
    printVec(randomVec, "random vec");
    return randomVec.size() == wordsPerPlayer;
}

bool getRandomCardTopicsForTeamCardsFINISHED()
{
    ;
}

bool getRandomCardTopicsForTeamRECCUR()
{
    RandomGenerator randomGenerator(true);
    CardRepository cardRepo;
    cardRepo.fetchGameCardTopcis();

}

bool getRandomCardTopicsForTeamNORECCUR()
{
    ;
}

int main()
{
    const int wordsPerPlayer = 3, cardsPerTeam = 4;
    checkNumberOfTopicsIngetRandomTopicNumbersForPlayer(
        wordsPerPlayer, cardsPerTeam);
}