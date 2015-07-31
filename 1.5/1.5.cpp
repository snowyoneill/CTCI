#include <iostream>
#include <sstream>

using namespace std;

const char* compressString(char *str)
{
	int len = strlen(str);
	if(!len)
		return str;

	std::string *oStr = new std::string("");
	*oStr += (str[0]); //oStr->append(str[0]);
	int count = 1;

	for(int i=1; i<len; i++)
	{
		if(str[i] == str[i-1])
			count++;
		else
		{
			std::stringstream ss;
			ss << count;
			oStr->append(ss.str());
			*oStr += (str[i]);
			count = 1;
		}
	}

	if(oStr->length() < len)
		return oStr->c_str();
	else
		return str;
}

int main()
{
	char *str = "aabcccccaaa";
	//char *str = "abca";

	cout << str << endl;
	const char *ret = compressString(str);
	cout << ret << endl;

	return 0;
}