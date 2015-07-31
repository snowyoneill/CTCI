//#pragma comment(linker, "/out:1.1.exe")

#include <stdio.h>
#include <string.h>

bool uniqueChars(char *str1)
{
	int len = strlen(str1);
	if(len > 256)
		return false;

	bool *charsArr = new bool[256];
	memset(charsArr, 0, sizeof(bool)*256);

	for (int i = 0; i < len; i++)
	{
		unsigned char c = str1[i];
		if(charsArr[c])
			return false;
		charsArr[c] = true;
	}

	return true;
}

// assuming only a-z lowercase (26 letters)
// int is 4 bytes = 32 bits
bool uniqueChars2(char *str1)
{
	int len = strlen(str1);
	int checker = 0;

	for (int i = 0; i < len; i++)
	{
		char c = str1[i]-'a';
		if(checker & (1 << c))
			return false;
		else
			checker |= (1 << c);
	}

	return true;
}

int main(int argc, char *argv[])
{
	//char testString[] = "abc123";
	char *testString;

	if(argc < 2)
	{
		printf("Wrong no of args\n");
		return 0;
	}
	else
		testString = argv[1];

	bool ret = uniqueChars(testString);
	if(ret)
		printf("All characters are unique\n");
	else
		printf("Not unique\n");

	printf("test 2...assume only lower case letters = 26 possibilities\n");
	ret = uniqueChars2(testString);
	if(ret)
		printf("All characters are unique\n");
	else
		printf("Not unique\n");
}