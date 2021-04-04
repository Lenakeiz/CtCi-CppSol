/*
Assuming ASCII for the hash table one

Is the permutation case sensitive? Is the permutation with whitespaces?
*/

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//This should effectively be O(n) as we loop only through the string once
bool isPermutation_CompareOneInteger(string a, string b)
{
    //Let's exclude edge cases
    if (a.length() != b.length()) return false;

    int cumulation = 0;
    for (int i = 0; i < a.length(); i++)
    {
        cumulation += a[i];
    }

    for (int i = 0; i < b.length(); i++)
    {
        cumulation -= b[i];
    }

    if (cumulation == 0)
        return true;

    return false;
}
//This should effectively be O(n) as we loop only through the strings once
bool isPermutation_CompareHashmap(string a, string b)
{
    //Let's exclude edge cases
    if (a.length() != b.length()) return false;

    int hashMap[128] = { 0 };
    for (int i = 0; i < a.length(); i++)
    {
        hashMap[a[i]]++;
    }

    for (int i = 0; i < b.length(); i++)
    {
        if(hashMap[b[i]] == 0) return false;
        hashMap[b[i]]--;
    }
    return true;
}

//This is a 0(nlogn) as we just need to sort the string and then traverse once 
bool isPermutation_Sort(string a, string b)
{
    //Let's exclude edge cases
    if (a.length() != b.length()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    //At this point a and b should be equal in size
    for (int i = 0; (unsigned)i < a.length(); i++)
    {
        if (a[i] != b[i]) return false;
    }
    //Assuming the string is ASCII - 128 characters
    return true;
}

//This is a 0(nlogn) as we just need to sort the string and then traverse once 
bool isPermutation_SortSimplified(string a, string b)
{
    //Let's exclude edge cases
    if (a.length() != b.length()) return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
        return true;
    //Assuming the string is ASCII - 128 characters
    return false;
}

int main()
{
    //For this exercise please see them in pairs
    vector<string> testValues = { "abcde", "debca", "permutation", "notPermutation", "hey how are you ?" "how are uoy yeh ?" };

    for (int i = 0; (unsigned)i < testValues.size()-1; i++)
    {
        cout << "Testing " << testValues[i] << " - " << testValues[i+1] << " ::: Result: " << std::boolalpha << isPermutation_Sort(testValues[i], testValues[i+1]) << endl;
    }

    for (int i = 0; (unsigned)i < testValues.size() - 1; i++)
    {
        cout << "Testing " << testValues[i] << " - " << testValues[i + 1] << " ::: Result: " << std::boolalpha << isPermutation_SortSimplified(testValues[i], testValues[i + 1]) << endl;
    }

    for (int i = 0; (unsigned)i < testValues.size() - 1; i++)
    {
        cout << "Testing " << testValues[i] << " - " << testValues[i + 1] << " ::: Result: " << std::boolalpha << isPermutation_CompareHashmap(testValues[i], testValues[i + 1]) << endl;
    }

    for (int i = 0; (unsigned)i < testValues.size() - 1; i++)
    {
        cout << "Testing " << testValues[i] << " - " << testValues[i + 1] << " ::: Result: " << std::boolalpha << isPermutation_CompareOneInteger(testValues[i], testValues[i + 1]) << endl;
    }

    return 0;
}