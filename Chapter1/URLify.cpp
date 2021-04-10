#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//Assuming ASCII
//Ascii code of "Space" =  32

//Getting the pointer to the string
string URLifystring(string &toUrl, int sizeURL)
{
	string urlified = "";
	int numSpaces = 0;
	int i, j = 0;

	for (i = 0; i < sizeURL; i++)
	{
		if (toUrl[i] == ' ')
		{
			numSpaces++;
		}
	}

	//Going backward is a good trick so you fill up the extra spaces calculated with the urlLenght
	int urlLenght = sizeURL + numSpaces * 2;
	i = urlLenght - 1;
	
	//i writes to the position 
	for (j = sizeURL - 1 ; j >= 0; j--)
	{
		if (toUrl[j] != ' ')
		{
			toUrl[i--] = toUrl[j];
		}
		else
		{
			toUrl[i--] = '0';
			toUrl[i--] = '2';
			toUrl[i--] = '%';
		}
	}
	return toUrl;
}

//Wrong attempt, I didn t realize you needed to check for the number of spaces. Also did not realized that the not Urlified string has enough traling spaces to make up with the urlification
string URLify(string toUrl, int sizeURL)
{
	if (sizeURL == 0 && toUrl.size() == sizeURL)
		return toUrl;
	char* urlified = new char[sizeURL];
	int lastIdx = toUrl.find_last_of(" ");
	for (int i = lastIdx-1; i>=0; --i)
	{
		if (toUrl[i] == 32)
		{
			*urlified = '0';
			urlified++;
			*urlified = '2';
			urlified++;
			*urlified = '%';
			urlified++;
		}
		else
		{
			*urlified = (char)toUrl[i];
			urlified++;
		}
	}
	//Wrong Attempt
	return toUrl;
}

int main()
{
	vector<string> testValues = { "abcde", "Mr John Smith    ", "m u UT    ", "ccc ia o    " };
	vector<int>	   exactSize = {5,13,6,8};
	for (unsigned int i = 0; i < testValues.size(); i++)
	{
		cout << "URLify string of " << testValues[i] << " : " << URLifystring(testValues[i], exactSize[i]) << endl;
	}
	return 0;
}