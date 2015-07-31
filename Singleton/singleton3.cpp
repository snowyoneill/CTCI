#include <iostream>

using namespace std;

//class MyClass
//{
//private:
//  MyClass() { }
//
//public:
//  static MyClass * CreateInstance() { return new MyClass(); }
//};

class MyClass
{
private:
  MyClass() { }

public:
  //static MyClass * CreateInstance()
  //{
  //  static MyClass * aGlobalInst = new MyClass();
  //  return aGlobalInst;
  //}

  static MyClass & CreateInstance()
  {
    static MyClass * aGlobalInst = new MyClass();
    return *aGlobalInst;
  }
};

int main()
{
	//MyClass *first = MyClass::CreateInstance();
	//MyClass *second = MyClass::CreateInstance();
	//if(first == second)
	//	cout << "Same same" << endl;

	MyClass first = MyClass::CreateInstance();
	MyClass second = MyClass::CreateInstance();
	if(&first == &second)
		cout << "Same same" << endl;
}