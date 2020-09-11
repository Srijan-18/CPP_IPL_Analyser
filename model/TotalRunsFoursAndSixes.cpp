class TotalRunsFoursAndSixes
{
    int total_runs, fours, sixes;

public:
    TotalRunsFoursAndSixes() {}

    TotalRunsFoursAndSixes(int total_runs, int fours, int sixes)
    {
        this->total_runs = total_runs;
        this->fours = fours;
        this->sixes = sixes;
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
};