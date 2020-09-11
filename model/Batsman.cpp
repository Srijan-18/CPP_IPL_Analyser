#pragma once
#include <iostream>
#include "BattingStats.cpp"

using namespace std;

class Batsman
{
    string name;
    BattingStats battingStats;

public:
    Batsman(string name, BattingStats battingStats)
    {
        this->name = name;
        this->battingStats = battingStats;
    }

    string get_name()
    {
        return name;
    }

    BattingStats get_batting_stats()
    {
        return battingStats;
    }
};