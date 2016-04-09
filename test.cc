#include <cassert>
#include <iostream>
#include "forward_list.h"
#include "list.h"

int main()
{
//    ForwardList<int> x;
    List<int> x;

    assert(x.size() == 0);
    x.push_front(3);
    assert(x.size() == 1);
    assert(x[0] == 3);
    x.push_front(5);
    assert(x.size() == 2);
    assert(x[0] == 5);
    assert(x[1] == 3);
    x.insert(0, 10);
    assert(x.size() == 3);
    assert(x[0] == 10);
    assert(x[1] == 5);
    assert(x[2] == 3);
    x.insert(1, 11);
    assert(x.size() == 4);
    assert(x[0] == 10);
    assert(x[1] == 11);
    assert(x[2] == 5);
    assert(x[3] == 3);

    std::cout << "Success!" << std::endl;
    return 0;
}
