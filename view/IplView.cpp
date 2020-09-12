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
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE"
             << "\n** NAME: " << batsman.get_name()
             << "**\t\t** AVERAGE: " << batsman.get_batting_stats()->get_average() << " **" << endl;
        break;
    case IplModel::Batting_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING STRIKE RATE"
             << "\n** NAME: " << batsman.get_name()
             << "**\t\t** STRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << " **" << endl;
        break;
    case IplModel::Sixes_And_Fours:
        cout << "\nBATSMAN WITH MAXIMUM SIXES AND FOURS"
             << "\n** NAME: " << batsman.get_name()
             << "**\t\t** SIXES: " << batsman.get_batting_stats()->get_sixes() 
             << "**\t\t** FOURS: " << batsman.get_batting_stats()->get_fours() << " **" << endl;
        break;
    }
}