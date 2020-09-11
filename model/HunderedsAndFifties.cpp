class HunderedsAndFifties
{
    int hundereds, fifties;

public:
    HunderedsAndFifties() {}

    HunderedsAndFifties(int hundereds, int fifties)
    {
        this->hundereds = hundereds;
        this->fifties = fifties;
    }

    int get_hundereds()
    {
        return hundereds;
    }

    int get_fifties()
    {
        return fifties;
    }
};