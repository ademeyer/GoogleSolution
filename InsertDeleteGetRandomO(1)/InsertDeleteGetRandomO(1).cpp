// InsertDeleteGetRandomO(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
using namespace std;

class RandomizedSet 
{
    unordered_set<int> hashset;
public:
    RandomizedSet()
    {

    }

    bool insert(int val) 
    {
        if(hashset.count(val)) 
            return false;
        hashset.insert(val);
        return true;
    }

    bool remove(int val) 
    {
        if (!hashset.count(val))
            return false;
        hashset.erase(val);
        return true;
    }

    int getRandom() 
    {
        int n = hashset.size();
        unordered_set<int>::iterator it = hashset.begin();
        advance(it, rand() % n);
        return *it;
    }
};


int main()
{
    RandomizedSet rd;
    cout << "remove: " << (rd.remove(4) ? "TRUE" : "FALSE") << endl;
    cout << "insert: " << (rd.insert(4) ? "TRUE" : "FALSE") << endl;
    cout << "insert: " << (rd.insert(4) ? "TRUE" : "FALSE") << endl;
    cout << "remove: " << (rd.remove(4) ? "TRUE" : "FALSE") << endl;
    cout << "insert: " << (rd.insert(5) ? "TRUE" : "FALSE") << endl;
    cout << "insert: " << (rd.insert(6) ? "TRUE" : "FALSE") << endl;
    cout << "insert: " << (rd.insert(7) ? "TRUE" : "FALSE") << endl;
    cout << "random: " << rd.getRandom() << endl;
    cout << "random: " << rd.getRandom() << endl;
    cout << "random: " << rd.getRandom() << endl;
    cout << "random: " << rd.getRandom() << endl;
    cout << "random: " << rd.getRandom() << endl;

}
