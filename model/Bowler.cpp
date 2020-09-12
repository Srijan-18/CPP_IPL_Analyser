#pragma once
#include <iostream>
#include "BowlingStats.cpp"

using namespace std;

class Bowler
{
    string name;
    BowlingStats bowling_stats;

public:
    Bowler(string name, BowlingStats bowling_stats)
    {
        this->name = name;
        this->bowling_stats = bowling_stats;
    }

    string get_name()
    {
        return name;
    }

    BowlingStats* get_bowling_stats()
    {
        return &bowling_stats;
    }
};