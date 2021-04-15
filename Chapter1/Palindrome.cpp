#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//Assuming ASCII
//Ascii code of "Space" =  32


//Should be O(n)
bool isPalindrome(string str)
{
    std::bitset<128> ascii_set;
	int letters = str.length();
	for (unsigned i = 0; (int)i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			ascii_set.flip(tolower(str[i]));
		}
		else
		{
			letters--;
		}
	}

	if (remainder(letters, 2) == 0)
		return ascii_set.none();
	else
		return ascii_set.count() == 1;

}


int main()
{
	vector<string> testValues = { "Tact coa"};
	for (unsigned int i = 0; i < testValues.size(); i++)
	{
		cout << "Is the following string " << testValues[i] << " palindrome? :  " << std::boolalpha << isPalindrome(testValues[i]) << endl;
	}
	return 0;
}