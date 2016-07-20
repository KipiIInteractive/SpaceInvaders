#include "RankingSystem.h"

list<string> RankingSystem::playerNames;
list<int> RankingSystem::playerScores;

bool RankingSystem::init() {
    ifstream ranking("./ranking/current.ranking");
    if(ranking) {
        string pRank;
        string pName;
        int pScore;
        while(ranking >> pRank >> pName >> pScore) {
            RankingSystem::playerNames.push_back(pName);
            RankingSystem::playerScores.push_back(pScore);
        }
        ranking.close();
        return true;
    }
    return false;
}
