#ifndef RANKINGSYSTEM_H_INCLUDED
#define RANKINGSYSTEM_H_INCLUDED

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include "PlayerResources.h"

using namespace std;

class RankingSystem {
public:
    static list<string> playerNames;
    static list<int> playerScores;

    static bool init();
    static bool playerIsEligible();
};

#endif // RANKINGSYSTEM_H_INCLUDED
