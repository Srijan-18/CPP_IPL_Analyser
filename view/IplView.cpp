#pragma once
#include <iostream>
#include "../model/IplModel.cpp"

using namespace std;

class IplView
{
public:
    IplView() {}
    void display_batsman_data(Batsman, IplModel::SortingParameter);
};

void IplView::display_batsman_data(Batsman batsman, IplModel::SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case IplModel::Batting_Average:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE\n"
             << "\n** NAME: " << batsman.get_name()
             << "**\t\t** AVERAGE: " << batsman.get_batting_stats()->get_average() << " **" << endl;
        break;
    case IplModel::Batting_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING STRIKE RATE\n"
             << "\n** NAME: " << batsman.get_name()
             << "**\t\t** STRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << " **" << endl;
        break;
    default:
        break;
    }
}