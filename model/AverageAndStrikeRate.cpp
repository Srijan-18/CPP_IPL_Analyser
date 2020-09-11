class AverageAndStrikeRate
{
    double average, strike_rate;

public:
    AverageAndStrikeRate() {}

    AverageAndStrikeRate(double average, double strike_rate)
    {
        this->average = average;
        this->strike_rate = strike_rate;
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