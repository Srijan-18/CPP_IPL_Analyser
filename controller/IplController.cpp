#include <iostream>
#include "../model/IPlModel.cpp"
#include "../view/IPlView.cpp"

using namespace std;

void print_welcome_message();

class IplController
{

public:
    IplController() {}
    void display_data()
    {
        string batting_stats_file_path = "../resources/IPL2019FactsheetMostRuns.csv";
        IplModel ipl_model;
        IplView ipl_view;

        vector<Batsman> batsmen_data = ipl_model.load_batsmen_data(batting_stats_file_path);

        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data,ipl_model.Batting_Average);
        ipl_view.display_batsman_data(batsmen_data.at(0),ipl_model.Batting_Average);

        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data,ipl_model.Batting_Strike_Rate);
        ipl_view.display_batsman_data(batsmen_data.at(0),ipl_model.Batting_Strike_Rate);

        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data,ipl_model.Sixes_And_Fours);
        ipl_view.display_batsman_data(batsmen_data.at(0),ipl_model.Sixes_And_Fours);

        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data,ipl_model.Strike_Rate_With_Sixes_And_Fours);
        ipl_view.display_batsman_data(batsmen_data.at(0),ipl_model.Strike_Rate_With_Sixes_And_Fours);
    }
};

int main()
{
    print_welcome_message();
    
    IplController ipl_controller;
    ipl_controller.display_data();

    return 0;
}

void print_welcome_message()
{
    cout << "\n\t\t***** WELCOME TO IPL ANALYSER *****\n"
         << endl;
}