#include <iostream>

struct simpleStruct {
	int tot;
};

void modifyStruct(simpleStruct str)
{
	str.tot = 0;
}

void modifyStruct1(simpleStruct *str)
{
	str->tot = 1;
}

void modifyStruct2(simpleStruct &str)
{
	str.tot = 2;
}

int main()
{
	simpleStruct s;

	s.tot = -1;
	
	std::cout << s.tot << std::endl;

	modifyStruct(s);
	std::cout << s.tot << std::endl;

	modifyStruct1(&s);
	std::cout << s.tot << std::endl;

	modifyStruct2(s);
	std::cout << s.tot << std::endl;

	return 0;
}