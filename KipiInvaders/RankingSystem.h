#ifndef RANKINGSYSTEM_H_INCLUDED
#define RANKINGSYSTEM_H_INCLUDED

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include "PlayerResources.h"

using namespace std;

class RankingSystem {
    static void updateRankingFile();
public:
    static list<string> playerNames;
    static list<int> playerScores;

    static bool init();
    static bool playerIsEligible();

    static void addPlayerToRankList(string pName);

};

#endif // RANKINGSYSTEM_H_INCLUDED
