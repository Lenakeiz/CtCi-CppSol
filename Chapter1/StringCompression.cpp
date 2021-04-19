#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//Assuming ASCII
//Should be O(n)
//This solution seems to be more optimized than the one proposed in the book, may need to discuss this with someone.
string StringCompression(string strA)
{
	int letA = strA.length();
	string strAcopy(letA, ' ');

	char currCharacter = strA[0];
	int charCount = 1;
	int currCopyCounter = 0;

	for (unsigned i = 0; (int)i < letA - 1; i++)
	{
		if (currCharacter == strA[i + 1])
		{
			charCount++;
		}
		else
		{
			if (currCopyCounter < letA)
			{
				strAcopy[currCopyCounter++] = currCharacter;
				strAcopy[currCopyCounter++] = to_string(charCount)[0];

				currCharacter = strA[i + 1];
				charCount = 1;
			}
			else 
			{
				//abort as we already finished the current string count 
				return strA;
			}
		}
	}

	strAcopy[currCopyCounter++] = currCharacter;
	strAcopy[currCopyCounter++] = to_string(charCount)[0];

	return strAcopy;
}

int main()
{
	vector<string> testValuesA = { "aabcccccaaa","abcdeabcde","aabccccffffGREcdea", "aabccccffffdddddea" }; //a2b1c4f4G1R1E1c1d1e1a1
	for (unsigned int i = 0; i < testValuesA.size(); i++)
	{
		cout << testValuesA[i] << ":" << StringCompression(testValuesA[i]) << endl;
	}
	return 0;
}