//http://www.cplusplus.com/reference/functional/greater/

#include <iostream>
#include <algorithm>
#include <vector>
 
bool greater_than(int a, int b)
{
    return a > b;
}
 
int main()
{
    //std::vector<int> vector = {2, 4, 6, 1, 3, 5};
    //auto begin = vector.begin();
    //auto end = vector.end();
	int myints[] =  {2, 4, 6, 1, 3, 5};
	std::vector<int> vector(myints,myints + 6);
	std::vector<int>::iterator begin = vector.begin();
	std::vector<int>::iterator end = vector.end();
 
	//std::make_heap(begin, end, std::greater <int>());
    std::make_heap(begin, end, greater_than);
    std::cout << "The minimum value: " << vector.front() << std::endl;
    return 0;
}