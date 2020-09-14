#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "../libraries/csvFileReader.cpp"
#include "Batsman.cpp"
#include "Bowler.cpp"
#include "Allrounder.cpp"
#include "../enums/IplEnums.cpp"

using namespace IplEnums;

class IplModel
{
    vector<vector<string>> read_data(string file_path)
    {
        CSV_Reader csv_operation;
        return csv_operation.read_file(file_path);
    }

public:
    IplModel() {}
    vector<Batsman> load_batsmen_data(string);
    vector<Batsman> sort_batsmen_data(vector<Batsman>, SortingParameter);
    vector<Bowler> load_bowler_data(string);
    vector<Bowler> sort_bowler_data(vector<Bowler>, SortingParameter);
    vector<Allrounder> load_all_rounder_data(vector<Batsman>, vector<Bowler>);
    vector<Allrounder> sort_all_rounder_data(vector<Allrounder>, SortingParameter);
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
    case SortingParameter::Batting_Average:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_average() > second_batsman.get_batting_stats()->get_average();
        });
        break;
    case SortingParameter::Batting_Strike_Rate:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate();
        });
        break;
    case SortingParameter::Sixes_And_Fours:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return ((first_batsman.get_batting_stats()->get_fours() + first_batsman.get_batting_stats()->get_sixes()) > (second_batsman.get_batting_stats()->get_fours() + second_batsman.get_batting_stats()->get_sixes()));
        });
        break;
    case SortingParameter::Strike_Rate_With_Sixes_And_Fours:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate() &&
                   ((first_batsman.get_batting_stats()->get_fours() + first_batsman.get_batting_stats()->get_sixes()) > (second_batsman.get_batting_stats()->get_fours() + second_batsman.get_batting_stats()->get_sixes()));
        });
        break;
    case SortingParameter::Batting_Average_And_Strike_Rate:
        sort(batsmen_data.begin(), batsmen_data.end(), [](Batsman &first_batsman, Batsman &second_batsman) -> bool {
            return ((first_batsman.get_batting_stats()->get_average() > second_batsman.get_batting_stats()->get_average()) &&
                    (first_batsman.get_batting_stats()->get_strike_rate() > second_batsman.get_batting_stats()->get_strike_rate()));
        });
        break;
    case SortingParameter::Most_Runs_With_Best_Average:
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
        current_bowler_stats.wickets = stoi(bowler_csv_data.at(player_count).at(6));
        string bowler_name = bowler_csv_data.at(player_count).at(1);

        Bowler bowler(bowler_name, current_bowler_stats);
        bowler_data.push_back(bowler);
    }

    return bowler_data;
}

vector<Bowler> IplModel::sort_bowler_data(vector<Bowler> bowler_data, SortingParameter sorting_parameter)
{
    vector<Bowler> required_bowler_data;
    switch (sorting_parameter)
    {
    case SortingParameter::Bowling_Average:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            return first_bowler.get_bowling_stats()->average < second_bowler.get_bowling_stats()->average;
        });

        for (int bowler_count = 0; bowler_count < bowler_data.size(); bowler_count++)
            if (bowler_data.at(bowler_count).get_bowling_stats()->average != 0)
                required_bowler_data.push_back(bowler_data.at(bowler_count));
        break;

    case SortingParameter::Bowling_Strike_Rate:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            return first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate;
        });

        for (int bowler_count = 0; bowler_count < bowler_data.size(); bowler_count++)
            if (bowler_data.at(bowler_count).get_bowling_stats()->strike_rate != 0)
                required_bowler_data.push_back(bowler_data.at(bowler_count));
        break;

    case SortingParameter::Bowling_Economy:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            return first_bowler.get_bowling_stats()->economy < second_bowler.get_bowling_stats()->economy;
        });

        for (int bowler_count = 0; bowler_count < bowler_data.size(); bowler_count++)
            if (bowler_data.at(bowler_count).get_bowling_stats()->economy != 0)
                required_bowler_data.push_back(bowler_data.at(bowler_count));
        break;

    case SortingParameter::Bowling_Strike_Rate_5W_4W:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            if (first_bowler.get_bowling_stats()->five_wicket_hauls != 0)
                return (first_bowler.get_bowling_stats()->five_wicket_hauls > second_bowler.get_bowling_stats()->five_wicket_hauls);
            else if (first_bowler.get_bowling_stats()->five_wicket_hauls == 0 && first_bowler.get_bowling_stats()->four_wicket_hauls != 0)
                return (first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate) && (first_bowler.get_bowling_stats()->four_wicket_hauls > second_bowler.get_bowling_stats()->four_wicket_hauls);
            else if (first_bowler.get_bowling_stats()->strike_rate == 0 || second_bowler.get_bowling_stats()->strike_rate == 0)
                return false;
            return first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate;
        });
        required_bowler_data = bowler_data;
        break;

    case SortingParameter::Bowling_Average_With_Best_Strike_Rate:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            return first_bowler.get_bowling_stats()->average < second_bowler.get_bowling_stats()->average && first_bowler.get_bowling_stats()->strike_rate < second_bowler.get_bowling_stats()->strike_rate;
        });

        for (int bowler_count = 0; bowler_count < bowler_data.size(); bowler_count++)
            if (bowler_data.at(bowler_count).get_bowling_stats()->average != 0 && bowler_data.at(bowler_count).get_bowling_stats()->strike_rate != 0)
                required_bowler_data.push_back(bowler_data.at(bowler_count));
        break;

    case SortingParameter::Bowling_Average_With_Most_Wickets:
        sort(bowler_data.begin(), bowler_data.end(), [](Bowler &first_bowler, Bowler &second_bowler) -> bool {
            return first_bowler.get_bowling_stats()->average < second_bowler.get_bowling_stats()->average && first_bowler.get_bowling_stats()->wickets > second_bowler.get_bowling_stats()->wickets;
        });

        for (int bowler_count = 0; bowler_count < bowler_data.size(); bowler_count++)
            if (bowler_data.at(bowler_count).get_bowling_stats()->average != 0 && bowler_data.at(bowler_count).get_bowling_stats()->wickets != 0)
                required_bowler_data.push_back(bowler_data.at(bowler_count));
        break;
    }

    return required_bowler_data;
}

vector<Allrounder> IplModel::load_all_rounder_data(vector<Batsman> batsmen, vector<Bowler> bowlers)
{
    vector<Allrounder> allrounders;
    for (int batsman_count = 0; batsman_count < batsmen.size(); batsman_count++)
    {
        for (int bowler_count = 0; bowler_count < bowlers.size(); bowler_count++)
        {
            if (batsmen.at(batsman_count).get_name() == bowlers.at(bowler_count).get_name())
            {
                Allrounder allrounder;
                allrounder.name = batsmen.at(batsman_count).get_name();
                allrounder.batting_average = batsmen.at(batsman_count).get_batting_stats()->get_average();
                allrounder.bowling_average = bowlers.at(bowler_count).get_bowling_stats()->average;
                allrounder.runs = batsmen.at(batsman_count).get_batting_stats()->get_total_runs();
                allrounder.wickets = bowlers.at(bowler_count).get_bowling_stats()->wickets;
                allrounders.push_back(allrounder);
            }
        }
    }

    return allrounders;
}

vector<Allrounder> IplModel::sort_all_rounder_data(vector<Allrounder> all_rounders, SortingParameter sorting_parameter)
{
    vector<Allrounder> required_allrounder_data;
    switch (sorting_parameter)
    {
    case Batting_And_Bowling_Averages:
        sort(all_rounders.begin(), all_rounders.end(), [](Allrounder &first_allrounder, Allrounder &second_allrounder) -> bool {
            return first_allrounder.batting_average > second_allrounder.batting_average && first_allrounder.bowling_average < second_allrounder.bowling_average;
        });

        for (int all_rounder_count = 0; all_rounder_count < all_rounders.size(); all_rounder_count++)
        {
            if (all_rounders.at(all_rounder_count).batting_average != 0 && all_rounders.at(all_rounder_count).bowling_average)
                required_allrounder_data.push_back(all_rounders.at(all_rounder_count));
        }
        break;

    case Most_Runs_And_Wickets:
        sort(all_rounders.begin(), all_rounders.end(), [](Allrounder &first_allrounder, Allrounder &second_allrounder) -> bool {
            return first_allrounder.runs > second_allrounder.runs && first_allrounder.wickets > second_allrounder.wickets;
        });
        required_allrounder_data = all_rounders;
    }
    
    return required_allrounder_data;
}