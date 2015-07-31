#include <iostream>

class Base
{
	int i;
	Base(){
		std::cout<<"Base constructor "<<std::endl;
	}

public:
	Base(int i){
		Base();
	}

	void BaseMethod(){
		std::cout<<"Base Method called "<<std::endl;
	}

	friend Base* createObj();

};

class Derived : public Base
{
	int j;
public:
	Derived()// Doesnt work - cannot access private constructor of base.
	Derived()// : Base(0)
	{
		std::cout<<"call of Derived constructor "<<std::endl;
	}

	void DerivedMethod()
	{
		std::cout<<"Derive Method called "<<std::endl;
	}
};

Base* createObj()
{
	Base *Bobj = new Base();
	return Bobj;
}

int main()
{
	Base *Bobj = createObj();
	Bobj->BaseMethod();
	Derived Dobj;
	Dobj.DerivedMethod();

	return 0;
}