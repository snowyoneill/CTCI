#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

void replaceSpaces(char *str, int sLen)
{
	int wI = sLen - 1;

	bool firstCharF = false;

	for(int i=wI; i>=0; i--)
	{
		char c = str[i];
		if(c != ' ' && !firstCharF)
			firstCharF = true;

		if(firstCharF)
		{
			if(c != ' ')
			{
				str[wI] = str[i];
				wI--;
			}
			else
			{
				str[wI] = '0';
				str[wI-1] = '2';
				str[wI-2] = '%';
				wI -= 3;
			}
		}
	}
}

int main()
{
			   //"Mr%20Dohn%20Smith"
	char str[] = "Mr John Smith    ";
	int sLen = strlen(str);

	cout << "'" << str << "'" << endl;
	replaceSpaces(str, sLen);
	cout << "'" << str << "'" << endl;


	return 0;
}