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

bool RankingSystem::playerIsEligible() {
    if(player->getScore() >= RankingSystem::playerScores.back()) {
        return true;
    }
    return false;
}

void RankingSystem::addPlayerToRankList(string pName) {
    int pRank = 1;
    list<string>::iterator it2 = RankingSystem::playerNames.begin();
    for(list<int>::iterator it = RankingSystem::playerScores.begin(); it != RankingSystem::playerScores.end(); it++) {
        if(player->getScore() >= (*it)) {
            RankingSystem::playerScores.insert(it, player->getScore());
            RankingSystem::playerScores.pop_back();

            RankingSystem::playerNames.insert(it2, pName);
            RankingSystem::playerNames.pop_back();
            break;
        }
        pRank++;
        it2++;
    }
    RankingSystem::updateRankingFile();
}

void RankingSystem::updateRankingFile() {
    ofstream rankingFileOutput("./ranking/current.ranking");
    if(rankingFileOutput) {
        int pRank = 1;
        list<int>::iterator it = RankingSystem::playerScores.begin();
        list<string>::iterator it2 = RankingSystem::playerNames.begin();
        for(; it != RankingSystem::playerScores.end(); it++, it2++) {
            rankingFileOutput << to_string(pRank) << ". " << (*it2) << " " << (*it) << "\n";
            pRank++;
        }
        rankingFileOutput.close();

    }
}
