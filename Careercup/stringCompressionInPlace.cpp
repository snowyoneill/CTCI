//http://www.careercup.com/question?id=7449675

#include <iostream>
#include <string>

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

void stringCompressInPlace(std::string &s)
{
	int readIdx = 0, writeIdx = 0;

	char c = s[0];
	int count = 1;
	readIdx = 1;
	for(int i=1; i<s.length(); i++)
	{
		char nextChr = s[i];
		if(c == nextChr)
			count++;
		else
		{
			string num = SSTR(count);
			s.replace(readIdx, num.length(), num);
			readIdx += num.length();
			s[readIdx] = nextChr;
			readIdx++;
			c = nextChr;
			count = 1;
		}
	}
	string num = SSTR(count);
	s.replace(readIdx, num.length(), num);
	readIdx += num.length();
	s.resize(readIdx);
}

int main()
{
	std::string s = "aabbbccc";

	cout << s << endl;

	stringCompressInPlace(s);

	cout << s << endl;

	return 0;
}