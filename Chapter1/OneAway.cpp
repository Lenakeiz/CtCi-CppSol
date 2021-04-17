#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//Assuming ASCII
//Should be O(n)
//This solution seems to be more optimized than the one proposed in the book, may need to discuss this with someone.
bool isOneEditAway(string strA, string strB)
{
	int letA = strA.length();
	int letB = strB.length();
	std::bitset<128> ascii_set;

	for (unsigned i = 0; (int)i < max(letA,letB); i++)
	{
		if (i < letA)
		{
			ascii_set.flip(tolower(strA[i]));
		}
		if (i < letB)
		{
			ascii_set.flip(tolower(strB[i]));
		}
	}

	bool retValue = false;

	if (letA != letB)
	{
		retValue = ascii_set.count() < 2;
	}
	else
	{
		retValue = ascii_set.count() <= 2;
	}

	return retValue;

}

int main()
{
	vector<string> testValuesA = { "pale", "pale", "pale", "pale" };
	vector<string> testValuesB = { "ple", "pales", "bale" , "bake" };
	for (unsigned int i = 0; i < testValuesA.size(); i++)
	{
		cout << testValuesA[i] << " , " << testValuesB[i] << " one edit away?" << std::boolalpha << isOneEditAway(testValuesA[i], testValuesB[i]) << endl;
	}
	return 0;
}