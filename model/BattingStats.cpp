class BattingStats
{

    int total_runs, fours, sixes, hundereds, fifties;
    double average, strike_rate;

public:
    BattingStats() {}

    BattingStats set_total_runs(int total_runs)
    {
        this->total_runs = total_runs;
    }

    BattingStats set_fours(int fours)
    {
        this->fours = fours;
    }

    BattingStats set_sixes(int sixes)
    {
        this->sixes = sixes;
    }

    BattingStats set_hundereds(int hundereds)
    {
        this->hundereds = hundereds;
    }

    BattingStats set_fifties(int fifties)
    {
        this->fifties = fifties;
    }

    BattingStats set_average(double average)
    {
        this->average = average;
    }

    BattingStats set_strike_rate(double strike_rate)
    {
        this->strike_rate = strike_rate;
    }

    int get_total_runs()
    {
        return total_runs;
    }

    int get_fours()
    {
        return fours;
    }

    int get_sixes()
    {
        return sixes;
    }

    int get_hundereds()
    {
        return hundereds;
    }

    int get_fifties()
    {
        return fifties;
    }

    int get_average()
    {
        return average;
    }

    int strike_rate()
    {
        return strike_rate;
    }
};