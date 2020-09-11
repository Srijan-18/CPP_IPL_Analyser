#pragma once
#include "TotalRunsFoursAndSixes.cpp"
#include "HunderedsAndFifties.cpp"
#include "AverageAndStrikeRate.cpp"

class BattingStats
{
    TotalRunsFoursAndSixes total_runs_fours_and_sixes;
    HunderedsAndFifties hundereds_and_fifties;
    AverageAndStrikeRate average_and_strike_rate;

public:
    BattingStats() {}

    BattingStats(TotalRunsFoursAndSixes total_runs_fours_and_sixes, HunderedsAndFifties hundereds_and_fifties, AverageAndStrikeRate average_and_strike_rate)
    {
        this->total_runs_fours_and_sixes = total_runs_fours_and_sixes;
        this->hundereds_and_fifties = hundereds_and_fifties;
        this->average_and_strike_rate = average_and_strike_rate;
    }

    TotalRunsFoursAndSixes get_total_runs_fours_and_sixes()
    {
        return total_runs_fours_and_sixes;
    }

    HunderedsAndFifties get_hundereds_and_fifties()
    {
        return hundereds_and_fifties;
    }

    AverageAndStrikeRate get_average_and_strike_rate()
    {
        return average_and_strike_rate;
    }
};