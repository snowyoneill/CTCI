#include <stdio.h>
#include <string.h>

bool isPermutation(char *str1, char *str2)
{
	int l1 = strlen(str1);
	int l2 = strlen(str2);

	if(l1 != l2)
		return false;

	for (int i = 0; i < l1; i++)
	{
		char c = str1[i];
		bool found = false;
		for (int j = 0; j < l1; j++)
		{
			if(c == str2[j])
			{
				found = true;
				str2[j] = '0';
				break;
			}
		}
		if(!found)
			return false;
	}
	return true;
}

int main()
{
	char *str1 = "abcc";
	char *str2 = "dcba";

	bool ret = isPermutation(str1, str2);

	printf("isPermutation: %d\n", ret);

	return 0;
}