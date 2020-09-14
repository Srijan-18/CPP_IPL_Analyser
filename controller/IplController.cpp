#include <iostream>
#include "../model/IPlModel.cpp"
#include "../view/IPlView.cpp"

using namespace std;

void print_welcome_message();

class IplController
{
    const string batting_stats_file_path = "../resources/IPL2019FactsheetMostRuns.csv";
    const string bowling_stats_file_path = "../resources/IPL2019FactsheetMostWkts.csv";
    IplModel ipl_model;
    IplView ipl_view;
    vector<Batsman> batsmen_data;
    vector<Bowler> bowler_data;

public:
    IplController()
    {
        batsmen_data = ipl_model.load_batsmen_data(batting_stats_file_path);
        bowler_data = ipl_model.load_bowler_data(bowling_stats_file_path);
    }

    void print_welcome_message()
    {
        ipl_view.display_welcome_message();
    }

    void perform_operations()
    {
        bool repeat = true;
        while (repeat)
        {
            int choice = ipl_view.getChoice();

            switch (choice)
            {
            case 1:
                display_best_batting_average();
                break;
            case 2:
                display_best_batting_strike_rate();
                break;
            case 3:
                display_most_sixes_and_fours();
                break;
            case 4:
                display_best_strike_rate_with_sixes_and_fours();
                break;
            case 5:
                display_best_batting_average_and_strike_rate();
                break;
            case 6:
                display_best_average_with_most_runs();
                break;
            case 7:
                display_best_bowling_average();
                break;
            case 8:
                display_best_bowling_strike_rate();
                break;
            case 9:
                display_best_bowling_economy();
                break;
            case 10:
                best_bowling_strike_rate_with_5w_4w();
                break;
            default:
                repeat = false;
            }
        }
    }

    void display_best_batting_average()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Batting_Average);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Batting_Average);
    }

    void display_best_batting_strike_rate()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Batting_Strike_Rate);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Batting_Strike_Rate);
    }

    void display_most_sixes_and_fours()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Sixes_And_Fours);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Sixes_And_Fours);
    }

    void display_best_strike_rate_with_sixes_and_fours()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Strike_Rate_With_Sixes_And_Fours);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Strike_Rate_With_Sixes_And_Fours);
    }

    void display_best_batting_average_and_strike_rate()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Batting_Average_And_Strike_Rate);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Batting_Average_And_Strike_Rate);
    }

    void display_best_average_with_most_runs()
    {
        batsmen_data = ipl_model.sort_batsmen_data(batsmen_data, ipl_model.Most_Runs_With_Best_Average);
        ipl_view.display_batsman_data(batsmen_data.at(0), ipl_model.Most_Runs_With_Best_Average);
    }

    void display_best_bowling_average()
    {
        bowler_data = ipl_model.sort_bowler_data(bowler_data, ipl_model.Bowling_Average);
        ipl_view.display_bowler_data(bowler_data.at(0), ipl_model.Bowling_Average);
    }

    void display_best_bowling_strike_rate()
    {
        bowler_data = ipl_model.sort_bowler_data(bowler_data, ipl_model.Bowling_Strike_Rate);
        ipl_view.display_bowler_data(bowler_data.at(0), ipl_model.Bowling_Strike_Rate);
    }

    void display_best_bowling_economy()
    {
        bowler_data = ipl_model.sort_bowler_data(bowler_data, ipl_model.Bowling_Economy);
        ipl_view.display_bowler_data(bowler_data.at(0), ipl_model.Bowling_Economy);
    }

    void best_bowling_strike_rate_with_5w_4w()
    {
        bowler_data = ipl_model.sort_bowler_data(bowler_data, ipl_model.Bowling_Strike_Rate_5W_4W);
        ipl_view.display_bowler_data(bowler_data.at(0), ipl_model.Bowling_Strike_Rate_5W_4W);
    }
};
