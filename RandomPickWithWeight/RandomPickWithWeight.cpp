// RandomPickWithWeight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class Solution {
private:
    std::vector<int> prefixSums;
    int totalSum;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;

public:
    Solution(std::vector<int>& w) {
        prefixSums.resize(w.size());
        prefixSums[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            prefixSums[i] = prefixSums[i - 1] + w[i];
        }
        totalSum = prefixSums.back();
        std::random_device rd;
        gen = std::mt19937(rd());
        dis = std::uniform_int_distribution<int>(1, totalSum);
    }

    int pickIndex() {
        int randomNum = dis(gen);
        auto it = std::lower_bound(prefixSums.begin(), prefixSums.end(), randomNum);
        return it - prefixSums.begin();
    }
};
int main()
{

}
