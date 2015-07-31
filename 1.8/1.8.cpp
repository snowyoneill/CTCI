#include <iostream>

using namespace std;

bool isRotation(char *str1, char *str2)
{
	std::string str = str1;
	std::string chkStr = str2;
	chkStr += str2;

	if(chkStr.find(str) != std::string::npos)
		return true;

	return false;
}

int main()
{
	char *str1 = "waterbottle";
	char *str2 = "erbottlewat";

	bool rotation = isRotation(str1, str2);

	cout << "isRotation: " << rotation << endl;

	return 0;
}