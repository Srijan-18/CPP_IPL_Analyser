class BattingStats
{

    int total_runs, fours, sixes, hundereds, fifties;
    double average, strike_rate;

public:
    BattingStats() {}

    void set_total_runs(int total_runs)
    {
        this->total_runs = total_runs;
    }

    void set_fours(int fours)
    {
        this->fours = fours;
    }

    void set_sixes(int sixes)
    {
        this->sixes = sixes;
    }

    void set_hundereds(int hundereds)
    {
        this->hundereds = hundereds;
    }

    void set_fifties(int fifties)
    {
        this->fifties = fifties;
    }

    void set_average(double average)
    {
        this->average = average;
    }

    void set_strike_rate(double strike_rate)
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

    double get_average()
    {
        return average;
    }

    double get_strike_rate()
    {
        return strike_rate;
    }
};