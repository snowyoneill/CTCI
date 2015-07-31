#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

std::string printBinaryDouble(double d)
{
	if(d < 0 || d > 1) return "Error";

	int c = 0;
	std::string s = "";
	std::stringstream ss;
	while(d != 0 && c < 32)
	{
		ss << int(d * 2);
		s += ss.str();
		d = fmod(d*2, 1);
		c++;
	}

	return (d != 0) ? "Error" : s;
}

int main()
{
	double test = 0.72;

	std::string res = printBinaryDouble(test);

	if(res != "Error")
		std::cout << "0." << res << std::endl;
	else
		std::cout << res << std::endl;

	return 0;
}