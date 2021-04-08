#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//Assuming ASCII
//Ascii code of "Space" =  32

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
}

int main()
{
	vector<string> testValues = { "abcde", "mam mia", "m u UT", "ccc ia o  " };
	vector<int>	   exactSize = { 5,9,10,12 };
	for (unsigned int i = 0; i < testValues.size(); i++)
	{
		cout << "URLify string of " << testValues[i] << " : " << URLify(testValues[i], exactSize[i]) << endl;
	}
	return 0;
}