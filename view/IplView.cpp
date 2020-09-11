#pragma once
#include <iostream>
#include "../model/IplModel.cpp"

using namespace std;

class IplView
{
public:
    IplView() {}
    void display_batsman_with_best_batting_average(Batsman);
};

void IplView::display_batsman_with_best_batting_average(Batsman batsman)
{
    cout << "\nBATSMAN WITH BEST BATTING AVERAGE\n"
         << "**\nNAME: " << batsman.get_name()
         << "**\t\tAVERAGE: " << batsman.get_batting_stats().get_average() << "**" << endl;
}