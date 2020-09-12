#pragma once
#include <iostream>
#include "../model/IplModel.cpp"

using namespace std;

class IplView
{
public:
    IplView() {}
    void display_batsman_data(Batsman, IplModel::SortingParameter);
    void display_bowler_data(Bowler);
};

void IplView::display_batsman_data(Batsman batsman, IplModel::SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case IplModel::Batting_Average:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**AVERAGE: " << batsman.get_batting_stats()->get_average() << "**" << endl;
        break;
    case IplModel::Batting_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING STRIKE RATE"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**STRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << "**" << endl;
        break;
    case IplModel::Sixes_And_Fours:
        cout << "\nBATSMAN WITH MAXIMUM SIXES AND FOURS"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**SIXES: " << batsman.get_batting_stats()->get_sixes()
             << "**\t\t** FOURS: " << batsman.get_batting_stats()->get_fours() << "**" << endl;
        break;
    case IplModel::Strike_Rate_With_Sixes_And_Fours:
        cout << "\nBATSMAN WITH BEST STRIKE RATE AND SIXES AND FOURS"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**STRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate()
             << "**\t\t**SIXES: " << batsman.get_batting_stats()->get_sixes()
             << "**\t\t**FOURS: " << batsman.get_batting_stats()->get_fours() << "**" << endl;
        break;
    case IplModel::Batting_Average_And_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE AND STRIKE RATE"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**AVERAGE: " << batsman.get_batting_stats()->get_average()
             << "**\t\t**STRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << "**" << endl;
        break;
    case IplModel::Most_Runs_With_Best_Average:
        cout << "\nBATSMAN WITH MOST RUNS AND MAXIMUM AVERAGE"
             << "\n**NAME: " << batsman.get_name()
             << "**\t\t**AVERAGE: " << batsman.get_batting_stats()->get_average()
             << "**\t\t**TOTAL RUNS: " << batsman.get_batting_stats()->get_total_runs() << "**" << endl;
        break;
    }
}

void IplView::display_bowler_data(Bowler bowler)
{
     cout << "\nBOWLER WITH BEST BOWLING AVERAGE"
             << "\n**NAME: " << bowler.get_name()
             << "**\t\t**AVERAGE: " << bowler.get_bowling_stats()->average << "**" << endl;
}