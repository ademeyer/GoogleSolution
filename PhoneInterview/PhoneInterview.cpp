// PhoneInterview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Example Input:
    std::vector<InputRow> input =
    {
        {1, 10, "Abby"},
        {5, 7, "Ben"},
        {6, 12, "Carla"},
        {15, 30, "David"}
    };

Example Output:
    std::vector<OutputRow> input =
    {
        {1, 5, "Abby"},
        {5, 6, "Abby", "Ben"},
        {6, 7,  "Abby", "Ben", "Carla"},
        {7, 10,  "Abby", "Carla"},
        {10, 12,  "Carla"},
        {15, 30, "David"}
    };

struct InputRow
{
    std::string people;
    int start;
    int end;
};

struct OutputRow
{
    int start;
    int end;
    std::vector<std::string> people;
};

Using std::vector<OutputRow> Convert(std::vector<InputRow>& input_rows) , solve the problem using c++
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

struct InputRow 
{
    int start;
    int end;
    std::string people;
};

struct OutputRow 
{
    int start;
    int end;
    std::vector<std::string> people;
};

std::vector<OutputRow> Convert(std::vector<InputRow>& input_rows) 
{
    std::map<int, std::set<std::string>> timeline;

    for (const auto& row : input_rows) 
    {
        std::istringstream ss(row.people);
        std::string person;
        while (std::getline(ss, person, ',')) 
        {
            timeline[row.start].insert(person);
            timeline[row.end].insert(person);
        }
    }

    std::vector<OutputRow> result;
    std::set<std::string> current_people;
    int prev_time = -1;

    for (const auto& n: timeline) 
    {

        if (prev_time != -1 && !current_people.empty()) 
        {
            result.push_back({ prev_time, n.first, std::vector<std::string>(current_people.begin(), current_people.end()) });
        }
        for (const auto& person : n.second) 
        {
            //if (!result.empty())
            {
                if (current_people.count(person) && n.first ) //(person.find("_end") != std::string::npos)
                {
                    current_people.erase(person);
                    continue;
                }
            }
            //else 
            {
                current_people.insert(person);
            }
        }
        prev_time = n.first;
    }

    return result;
}

int main() 
{
    std::vector<InputRow> input = 
    {
        {1, 10, "Abby"},
        {5, 7, "Ben"},
        {6, 12, "Carla"},
        {15, 30, "David"}
    };

    std::vector<OutputRow> output = Convert(input);

    for (const auto& row : output) 
    {
        std::cout << "Start: " << row.start << " | End: " << row.end << " | Names: ";
        for (const auto& name : row.people) {
            std::cout << name << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
