//http://www.geeksforgeeks.org/private-destructor/

#include <iostream>
 
// A class with private destuctor
class Test
{
	
	//*** No constructor specified i.e. the compiler will generate a default one ***

private:
	//Test() {}
    ~Test() {}
friend void destructTest(Test* );
};

//If the constructor/destructor is declared as private, then the class cannot be instantiated.
class TestDerived : public Test
{
public:
	//TestDerived() {}

};

// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
}
 
int main()
{
    // create an object
    Test *ptr = new Test(); //*** This works because the compiler generates a default constructor ***

    //TestDerived *ptr = new TestDerived();
 
    // destruct the object
    destructTest (ptr);
 
    return 0;
}

