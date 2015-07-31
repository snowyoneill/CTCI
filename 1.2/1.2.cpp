#include <stdio.h>
#include <string.h>

void reverse(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len/2; i++)
	{
		char c = str[i];
		str[i] = str[len - 1 -i];
		str[len - 1 -i] = c;
	} 
}

int main()
{
	//char *string = "abcde"; //string literals are stored in read only section of memory
							  //any attempt to modify the contents of a string literal invokes Undefined Behaviour

	char string[] = "abcde"; //array of characters

	printf("%s\n", &string);

	reverse(string);
	printf("%s\n", string);
	return 0;
}