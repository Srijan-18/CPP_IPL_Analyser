#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "../libraries/csvFileReader.cpp"
#include "Batsman.cpp"

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
        Strike_Rate_With_Sixes_And_Fours
    };

    IplModel() {}
    vector<Batsman> load_batsmen_data(string);
    vector<Batsman> sort_batsmen_data(vector<Batsman>, SortingParameter);
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
    case Strike_Rate_With_Sixes_And_Fours:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate() &&
                   ((first_batsman.get_batting_stats()->get_fours() + first_batsman.get_batting_stats()->get_sixes()) > (second_batsman.get_batting_stats()->get_fours() + second_batsman.get_batting_stats()->get_sixes()));
        });
        break;
    }
    return batsmen_data;
}