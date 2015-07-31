#include <iostream>

using namespace std;

/* 
 * test reference to pointers
 * http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer
 */

//global variable
int g_One=1;

void func(int*& rpInt)
{
  //Modify what rpInt and pvar is pointing to, to g_One
  rpInt=&g_One;

  //You can also allocate memory, depending on your requirements
  rpInt=new int;

  //Modify the variable rpInt points to
  *rpInt=3;
}

void test()
{
  int nvar=2;
  int* pvar=&nvar;
  func(pvar);
  
  cout << *pvar << endl;
}

//http://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations

void test2()
{
	int RollNum[1][4];
	for(int i=0; i<4; i++)
		RollNum[0][i] = i*10;

	int (*p)[4]=&RollNum[0]; //pointer to an array of 4 ints
	int *q[5]; //array of 5 pointers to integers

	p = NULL;
	int i=7;
	q[0] = &i;
}

void test3()
{
	char word1[] = "one";
	char word2[] = "two";
	char *words[2] = {word1, word2};

	char **argv = words;//&words[0];

	char c = (*argv)[1];
}

int main()
{
	test();
	test2();
	test3();
}