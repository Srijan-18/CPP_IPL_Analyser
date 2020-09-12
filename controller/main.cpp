#include <iostream>
#include "../model/IPlModel.cpp"
#include "../view/IPlView.cpp"

using namespace std;

void print_welcome_message();
void display_batsman_with_best_batting_average();

int main()
{
    print_welcome_message();
    display_batsman_with_best_batting_average();

    return 0;
}

void print_welcome_message()
{
    cout << "\n\t\t***** WELCOME TO IPL ANALYSER *****\n" << endl;
}

void display_batsman_with_best_batting_average()
{
    string batting_stats_file_path = "../resources/IPL2019FactsheetMostRuns.csv";
    IplModel ipl_model;

    vector<Batsman> batsmen_data = ipl_model.load_batsmen_data(batting_stats_file_path);

    batsmen_data = ipl_model.sort_by_batting_average(batsmen_data);
    
    IplView ipl_view;
    ipl_view.display_batsman_with_best_batting_average(batsmen_data.at(0));
}