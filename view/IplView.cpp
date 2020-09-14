#pragma once
#include <iostream>
#include "../enums/IplEnums.cpp"

using namespace IplEnums;
using namespace std;

class IplView
{
public:
    IplView() {}
    void display_welcome_message();
    int getChoice();
    void display_batsman_data(Batsman, SortingParameter);
    void display_bowler_data(Bowler, SortingParameter);
};

void IplView::display_welcome_message()
{
    cout << "\n\t\t***** WELCOME TO IPL ANALYSER *****\n";
}

int IplView::getChoice()
{
    int choice;

    cout << "\n\t\t##  MAKE INPUT ACCORDING TO CHOICE  ##\n";
    cout << "\n1.  Find Batsman With Top Batting Average\n2.  Find Batsman With Top Striking Rate\n3.  Find Batsman With Max 6(s) And 4(s)"
         << "\n4.  Find Batsman With Best Strike Rate With Sixes And Fours\n5.  Find Batsman With Great Average With Best Strike"
         << "\n6.  Find Batsman With Maximum Runs With Best Averages"
         << "\n7.  Find Bowler With Top Bowling Average\n8.  Find Bowler With Top Strike Rate"
         << "\n9.  Find Bowler With Best Economy Rate\n10. Find Bowler With Best Strike Rate With 5W And 4W"
         << "\n11. Find Bowler With Best Average And Best Strike Rate"
         << "\n12. Find Bowler With Best Average And Most Wickets"
         << "\nAny other to exit."
         << "\n\nYour Choice : ";

    cin >> choice;
    cin.get();
    return choice;
}

void IplView::display_batsman_data(Batsman batsman, SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case SortingParameter::Batting_Average:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average() << endl;
        break;
    case SortingParameter::Batting_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING STRIKE RATE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << endl;
        break;
    case SortingParameter::Sixes_And_Fours:
        cout << "\nBATSMAN WITH MAXIMUM SIXES AND FOURS"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSIXES: " << batsman.get_batting_stats()->get_sixes()
             << "\t\tFOURS: " << batsman.get_batting_stats()->get_fours() << endl;
        break;
    case SortingParameter::Strike_Rate_With_Sixes_And_Fours:
        cout << "\nBATSMAN WITH BEST STRIKE RATE AND SIXES AND FOURS"
             << "\nNAME: " << batsman.get_name()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate()
             << "\t\tSIXES: " << batsman.get_batting_stats()->get_sixes()
             << "\t\tFOURS: " << batsman.get_batting_stats()->get_fours() << endl;
        break;
    case SortingParameter::Batting_Average_And_Strike_Rate:
        cout << "\nBATSMAN WITH BEST BATTING AVERAGE AND STRIKE RATE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average()
             << "\t\tSTRIKE RATE: " << batsman.get_batting_stats()->get_strike_rate() << endl;
        break;
    case SortingParameter::Most_Runs_With_Best_Average:
        cout << "\nBATSMAN WITH MOST RUNS AND MAXIMUM AVERAGE"
             << "\nNAME: " << batsman.get_name()
             << "\t\tAVERAGE: " << batsman.get_batting_stats()->get_average()
             << "\t\tTOTAL RUNS: " << batsman.get_batting_stats()->get_total_runs() << endl;
        break;
    }
}

void IplView::display_bowler_data(Bowler bowler, SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case SortingParameter::Bowling_Average:
        cout << "\nBOWLER WITH BEST BOWLING AVERAGE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tAVERAGE: " << bowler.get_bowling_stats()->average << endl;
        break;
    case SortingParameter::Bowling_Strike_Rate:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tSTRIKE RATE: " << bowler.get_bowling_stats()->strike_rate << endl;
        break;
    case SortingParameter::Bowling_Economy:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tECONOMY: " << bowler.get_bowling_stats()->economy << endl;
        break;
    case SortingParameter::Bowling_Strike_Rate_5W_4W:
        cout << "\nBOWLER WITH BEST BOWLING STRIKE RATE WITH 5W AND 4W"
             << "\nNAME: " << bowler.get_name()
             << "\t\tSTRIKE_RATE: " << bowler.get_bowling_stats()->strike_rate
             << "\t\tFIVE WICKET HAULS: " << bowler.get_bowling_stats()->five_wicket_hauls
             << "\t\tFOUR WICKET HAULS: " << bowler.get_bowling_stats()->four_wicket_hauls
             << endl;
        break;
    case SortingParameter::Bowling_Average_With_Best_Strike_Rate:
        cout << "\nBOWLER WITH BEST BOWLING AVERAGE AND STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tBOWLING AVERAGE: " << bowler.get_bowling_stats()->average
             << "\t\tBOWLING STRIKE RATE: " << bowler.get_bowling_stats()->strike_rate
             << endl;
        break;
    case SortingParameter::Bowling_Average_With_Most_Wickets:
        cout << "\nBOWLER WITH BEST BOWLING AVERAGE AND STRIKE RATE"
             << "\nNAME: " << bowler.get_name()
             << "\t\tBOWLING AVERAGE: " << bowler.get_bowling_stats()->average
             << "\t\tWICKETS: " << bowler.get_bowling_stats()->wickets
             << endl;
        break;
    }
}