// NestedListWeightSumII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
// Abstract base class representing a Nested Integer, which
// could be either an integer or a nested list of integers.
class NestedInteger {
public:
    virtual ~NestedInteger() {}
    // Returns true if this NestedInteger holds a single
    // integer, rather than a nested list.
    virtual bool isInteger() const = 0;
    // Returns the single integer that this NestedInteger
    // holds, if it holds a single integer.
    virtual int getInteger() const = 0;
    // Returns the nested list that this NestedInteger
    // holds, if it holds a nested list.
    virtual const std::vector<NestedInteger*>&
    getList() const = 0;
};

// Concrete implementation of NestedInteger to hold a single
// integer.
class Integer : public NestedInteger {
    int value;

public:
    Integer(int value)
        : value(value)
    {
    }
    bool isInteger() const override { return true; }
    int getInteger() const override { return value; }
    const std::vector<NestedInteger*>&
    getList() const override
    {
        throw std::runtime_error("This is not a list");
    }
};

// Concrete implementation of NestedInteger to hold a list
// of NestedInteger objects.
class List : public NestedInteger {
    std::vector<NestedInteger*> list;

public:
    List(const std::vector<NestedInteger*>& list)
        : list(list)
    {
    }
    ~List()
    {
        for (auto item : list) {
            delete item; // Clean up memory to prevent leaks
        }
    }
    bool isInteger() const override { return false; }
    int getInteger() const override
    {
        throw std::runtime_error("This is not an integer");
    }
    const std::vector<NestedInteger*>&
    getList() const override
    {
        return list;
    }
};

// Flattens a nested list into a simple list of integers
// with their associated depths.
void flatten(const NestedInteger& ni, int depth,
             std::vector<std::pair<int, int> >& flatList,
             int& maxDepth)
{
    if (ni.isInteger()) {
        flatList.push_back({ ni.getInteger(), depth });
        maxDepth = std::max(maxDepth, depth);
    }
    else {
        for (auto item : ni.getList()) {
            flatten(*item, depth + 1, flatList, maxDepth);
        }
    }
}

// Calculates the inverse depth sum of a nested list.
int depthSumInverse(
    const std::vector<NestedInteger*>& nestedList)
{
    std::vector<std::pair<int, int> > flatList;
    int maxDepth = 0;
    for (auto item : nestedList) {
        flatten(*item, 0, flatList, maxDepth);
    }

    int sum = 0;
    for (const auto& p : flatList) {
        sum += p.first
               * (maxDepth + 1
                  - p.second); // Weight the value by its
                               // inverse depth
    }
    return sum;
}

*/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// Time:  O(n)
// Space: O(h)

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger 
{
public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };


class Solution 
{
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        vector<int> result;

        function<void(const NestedInteger&, int)> findDepthSumInverseHelper 
            = [&](const NestedInteger& list, int depth)
        {
            if (result.size() < depth + 1)
                result.emplace_back(0);

            if (list.isInteger())
                result[depth] += list.getInteger();
            else
            {
                for (const auto& l : list.getList())
                    findDepthSumInverseHelper(l, (depth + 1));
            }
        };

        for (const auto& list : nestedList)
            findDepthSumInverseHelper(list, 0);

        int sum = 0;

        for (int i = result.size() - 1; i >= 0; --i)
            sum += result[i] * (result.size() - i);

        return sum;
    }
};

int main()
{

}
