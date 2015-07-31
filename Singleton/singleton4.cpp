//class Singleton
//{
//  private:
//
//    static Singleton *p_inst;
//    Singleton();
//
//  public:
//
//    static Singleton * instance()
//    {
//      if (!p_inst)
//      {
//        p_inst = new Singleton();
//      }
//
//      return p_inst;
//    }
//};

#include <iostream>

using namespace std;

class Singleton
{
  public:
    static Singleton& Instance()
    {
        static Singleton inst;
        return inst;
    }

	void print_something()
	{
		cout << "Hello" << endl;
	}

  protected:

		// C++ 03
        // ========
        // Dont forget to declare these two. You want to make sure they
        // are unacceptable otherwise you may accidentally get copies of
        // your singleton appearing.

    //Singleton(); // Prevent construction
    //Singleton(const Singleton&); // Prevent construction by copying
    //Singleton& operator=(const Singleton&); // Prevent assignment
    //~Singleton(); // Prevent unwanted destruction

	Singleton() {} // Prevent construction
    Singleton(const Singleton&); // Prevent construction by copying
    Singleton& operator=(const Singleton&); // Prevent assignment
	~Singleton() {} // Prevent unwanted destruction
};

int main()
{
	Singleton &s = Singleton::Instance();
	s.print_something();

	//new MySingleton(); // Illegal
	//delete MySingleton::Instance(); // Illegal.
}