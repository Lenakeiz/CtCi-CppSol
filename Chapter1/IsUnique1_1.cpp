// IsUnique1_1.cpp : Chapter 1 exercise 1

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//This is a 0(n^2) method looping to the array twice
bool isUniqueChars(string str)
{
    if (str.length() > 128) return false;
    vector<bool> ascii_set(128);
    for (int i = 0; (unsigned)i < str.length(); i++)
    {
        //Treat the character as an int
        for (int i = 0; (unsigned)i < str.length(); i++)
        {
            int val = str[i];
            if (ascii_set[val]) return false;
            ascii_set[val] = true;
        }
        return true;
    }
    //Assuming the string is ASCII - 128 characters
    return true;
}

//This is a 0(nlogn) for sorting the vector
bool isUniqueChars_Sort(string str)
{
    if (str.length() > 128) return false;
    vector<bool> ascii_set(128);
    for (int i = 0; (unsigned)i < str.length(); i++)
    {
        sort(str.begin(), str.end());
        
        for (int i = 0; (unsigned)i < str.length() - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                return false;
            }                
        }
        return true;
    }
    //Assuming the string is ASCII - 128 characters
    return true;
}

int main()
{
    vector<string> testValues = {"abcde", "mamma mia", "mMuUtT", "ciao"};

    for ( auto word : testValues)
    {
        cout << "Testing: " << word << " Result: " << std::boolalpha << isUniqueChars(word) << endl;
    }

    for (auto word : testValues)
    {
        cout << "Testing: " << word << " Result: " << std::boolalpha << isUniqueChars_Sort(word) << endl;
    }

}
