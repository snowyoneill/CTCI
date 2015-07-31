
//http://apiexamples.com/cpp/algorithm/make_heap.html

#include <iostream>
#include <algorithm>
#include <vector>
 
int main()
{
    std::vector<int> vector = {2, 4, 6, 1, 3, 5};
    auto begin = vector.begin();
    auto end = vector.end();
 
    std::make_heap(begin, end);
    std::cout << "The maximum value: " << vector.front() << std::endl;
    return 0;
}