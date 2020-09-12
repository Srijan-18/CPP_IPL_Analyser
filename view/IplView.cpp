#pragma once
#include <iostream>
#include "../model/IplModel.cpp"

using namespace std;

class IplView
{
public:
    IplView() {}
    void display_batsman_data(Batsman, IplModel::SortingParameter);
    void display_bowler_data(Bowler, IplModel::SortingParameter);
};

void IplView::display_batsman_data(Batsman batsman, IplModel::SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case IplModel::Batting_Average:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average() << endl;
        break;
    case IplModel::Batting_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING STRIKE RATE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << endl;
        break;
    case IplModel::Sixes_And_Fours:
        cout << "\nBATSMAN WITH MAXIMUM SIXES AND FOURS"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSIXES: " << batsman.get_batting_stats()->get_sixes()
             << "\t\tFOURS: " << batsman.get_batting_stats()->get_fours() << endl;
        break;
    case IplModel::Strike_Rate_With_Sixes_And_Fours:
        cout << "\nBATSMAN WITH BEST STRIKE RATE AND SIXES AND FOURS"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate()
             << "\t\tSIXES: " << batsman.get_batting_stats()->get_sixes()
             << "\t\tFOURS: " << batsman.get_batting_stats()->get_fours() << endl;
        break;
    case IplModel::Batting_Average_And_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE AND STRIKE RATE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << endl;
        break;
    case IplModel::Most_Runs_With_Best_Average:
        cout << "\nBATSMAN WITH MOST RUNS AND MAXIMUM AVERAGE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average()
             << "\t\tTOTAL RUNS: " << batsman.get_batting_stats()->get_total_runs() << endl;
        break;
    }
}

void IplView::display_bowler_data(Bowler bowler, IplModel::SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case IplModel::Bowling_Average:
        cout << "\nBOWLER WITH BEST BOWLING AVERAGE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tAVERAGE: " << bowler.get_bowling_stats()->average << endl;
        break;
    case IplModel::Bowling_Strike_Rate:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tSTRIKE RATE: " << bowler.get_bowling_stats()->strike_rate << endl;
        break;
    case IplModel::Bowling_Economy:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tECONOMY: " << bowler.get_bowling_stats()->economy << endl;
        break;
    case IplModel::Bowling_Strike_Rate_5W_4W:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE WITH 5W AND 4W"
             << "\nNAME: " << bowler.get_name()
             << "\t\tSTRIKE_RATE: " << bowler.get_bowling_stats()->strike_rate 
             << "\t\tFIVE WICKET HAULS: " << bowler.get_bowling_stats()->five_wicket_hauls
             << "\t\tFOUR WICKET HAULS: " << bowler.get_bowling_stats()->four_wicket_hauls
             << endl;
        break;
    }
}