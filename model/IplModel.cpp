#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "../libraries/csvFileReader.cpp"
#include "Batsman.cpp"
#include "Bowler.cpp"

class IplModel
{
    vector<vector<string>> read_data(string file_path)
    {
        CSV_Reader csv_operation;
        return csv_operation.read_file(file_path);
    }

public:
    enum SortingParameter
    {
        Batting_Average = 1,
        Batting_Strike_Rate,
        Sixes_And_Fours,
        Strike_Rate_With_Sixes_And_Fours,
        Batting_Average_And_Strike_Rate,
        Most_Runs_With_Best_Average,
        Bowling_Average,
        Bowling_Strike_Rate,
        Bowling_Economy,
        Bowling_Strike_Rate_5W_4W
    };

    IplModel() {}
    vector<Batsman> load_batsmen_data(string);
    vector<Batsman> sort_batsmen_data(vector<Batsman>, SortingParameter);
    vector<Bowler> load_bowler_data(string);
    vector<Bowler> sort_bowler_data(vector<Bowler>, SortingParameter);
};

vector<Batsman> IplModel::load_batsmen_data(string file_path)
{
    vector<vector<string>> batsmen_csv_data = read_data(file_path);

    vector<Batsman> batsmen_data;

    for (int player_count = 0; player_count < batsmen_csv_data.size(); player_count++)
    {
        BattingStats current_batsman_stats;
        current_batsman_stats.set_total_runs(stoi(batsmen_csv_data.at(player_count).at(5)));
        current_batsman_stats.set_fours(stoi(batsmen_csv_data.at(player_count).at(12)));
        current_batsman_stats.set_sixes(stoi(batsmen_csv_data.at(player_count).at(13)));
        current_batsman_stats.set_hundereds(stoi(batsmen_csv_data.at(player_count).at(10)));
        current_batsman_stats.set_fifties(stoi(batsmen_csv_data.at(player_count).at(11)));
        current_batsman_stats.set_average(stod(batsmen_csv_data.at(player_count).at(7)));
        current_batsman_stats.set_strike_rate(stod(batsmen_csv_data.at(player_count).at(9)));
        string batsman_name = batsmen_csv_data.at(player_count).at(1);
        Batsman current_batsman(batsman_name, current_batsman_stats);
        batsmen_data.push_back(current_batsman);
    }
    return batsmen_data;
}

vector<Batsman> IplModel::sort_batsmen_data(vector<Batsman> batsmen_data, SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case Batting_Average:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_average() > second_batsman.get_batting_stats()->get_average();
        });
        break;
    case Batting_Strike_Rate:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate();
        });
        break;
    case Sixes_And_Fours:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return ((first_batsman.get_batting_stats()->get_fours() + first_batsman.get_batting_stats()->get_sixes()) > (second_batsman.get_batting_stats()->get_fours() + second_batsman.get_batting_stats()->get_sixes()));
        });
        break;
    case Strike_Rate_With_Sixes_And_Fours:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate() &&
                   ((first_batsman.get_batting_stats()->get_fours() + first_batsman.get_batting_stats()->get_sixes()) > (second_batsman.get_batting_stats()->get_fours() + second_batsman.get_batting_stats()->get_sixes()));
        });
        break;
    case Batting_Average_And_Strike_Rate:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return ((first_batsman.get_batting_stats()->get_average() > second_batsman.get_batting_stats()->get_average()) &&
                    (first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate()));
        });
        break;
    case Most_Runs_With_Best_Average:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return ((first_batsman.get_batting_stats()->get_total_runs() > second_batsman.get_batting_stats()->get_total_runs()) &&
                    (first_batsman.get_batting_stats()->get_average() > second_batsman.get_batting_stats()->get_average()));
        });
        break;
    }
    return batsmen_data;
}

vector<Bowler> IplModel::load_bowler_data(string file_path)
{
    vector<vector<string>> bowler_csv_data = read_data(file_path);
    vector<Bowler> bowler_data;
    for (int player_count = 0; player_count < bowler_csv_data.size(); player_count++)
    {
        BowlingStats current_bowler_stats;
        current_bowler_stats.average = stod(bowler_csv_data.at(player_count).at(8));
        current_bowler_stats.strike_rate = stod(bowler_csv_data.at(player_count).at(10));
        current_bowler_stats.economy = stod(bowler_csv_data.at(player_count).at(9));
        current_bowler_stats.four_wicket_hauls = stoi(bowler_csv_data.at(player_count).at(11));
        current_bowler_stats.five_wicket_hauls = stoi(bowler_csv_data.at(player_count).at(12));
        string bowler_name = bowler_csv_data.at(player_count).at(1);

        Bowler bowler(bowler_name, current_bowler_stats);
        bowler_data.push_back(bowler);
    }

    return bowler_data;
}

vector<Bowler> IplModel::sort_bowler_data(vector<Bowler> bowler_data, SortingParameter sorting_parameter)
{
    switch (sorting_parameter)
    {
    case Bowling_Average:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            if (first_bowler.get_bowling_stats()->average != 0 || second_bowler.get_bowling_stats()->average != 0)
                return false;
            return first_bowler.get_bowling_stats()->average < second_bowler.get_bowling_stats()->average;
        });
        break;
    case Bowling_Strike_Rate:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            if (first_bowler.get_bowling_stats()->strike_rate == 0 || second_bowler.get_bowling_stats()->strike_rate == 0)
                return false;
            return first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate;
        });
        break;
    case Bowling_Economy:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            if (first_bowler.get_bowling_stats()->economy == 0 || second_bowler.get_bowling_stats()->economy == 0)
                return false;
            return first_bowler.get_bowling_stats()->economy < second_bowler.get_bowling_stats()->economy;
        });
        break;
    case Bowling_Strike_Rate_5W_4W:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            if (first_bowler.get_bowling_stats()->five_wicket_hauls != 0)
                return (first_bowler.get_bowling_stats()->five_wicket_hauls > second_bowler.get_bowling_stats()->five_wicket_hauls);
            else if (first_bowler.get_bowling_stats()->five_wicket_hauls == 0 && first_bowler.get_bowling_stats()->four_wicket_hauls != 0)
                return (first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate) && (first_bowler.get_bowling_stats()->four_wicket_hauls > second_bowler.get_bowling_stats()->four_wicket_hauls);
            else if (first_bowler.get_bowling_stats()->strike_rate == 0 || second_bowler.get_bowling_stats()->strike_rate == 0)
                return false;
            return first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate;
        });
    }
    return bowler_data;
}