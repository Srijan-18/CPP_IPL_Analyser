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

    bool sort_by_average(Batsman first_batsman, Batsman second_batsman)
    {
        return first_batsman.get_batting_stats().get_average() < second_batsman.get_batting_stats().get_average();
    }

public:
    IplModel() {}
    vector<Batsman> load_batsmen_data(string);
    vector<Batsman> sort_by_batting_average(vector<Batsman>);
};

vector<Batsman> IplModel::load_batsmen_data(string file_path)
{
    vector<vector<string>> batsmen_csv_data = read_data(file_path);

    vector<Batsman> batsmen_data;

    for (int player_count = 0; player_count < batsmen_csv_data.size(); player_count++)
    {
        BattingStats current_batsman_stats;
        current_batsman_stats.set_total_runs(stoi(batsmen_csv_data.at(player_count).at(5)))
            .set_fours(stoi(batsmen_csv_data.at(player_count).at(12)))
            .set_sixes(stoi(batsmen_csv_data.at(player_count).at(13)))
            .set_hundereds(stoi(batsmen_csv_data.at(player_count).at(10)))
            .set_fifties(stoi(batsmen_csv_data.at(player_count).at(11)))
            .set_average(stod(batsmen_csv_data.at(player_count).at(7)))
            .set_strike_rate(stod(batsmen_csv_data.at(player_count).at(9)));
        string batsman_name = batsmen_csv_data.at(player_count).at(1);
        Batsman current_batsman(batsman_name, current_batsman_stats);

        batsmen_data.push_back(current_batsman);
    }
    return batsmen_data;
}

vector<Batsman> IplModel::sort_by_batting_average(vector<Batsman> batsmen_data)
{
    sort(batsmen_data.begin(), batsmen_data.end(), sort_by_average);
    return batsmen_data;
}
