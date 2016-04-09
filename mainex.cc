#include <iostream>
#include "array.h"

int main()
{
    Array<int> x;

    try {
        std::cout << x[2];
    }
    catch (const char *e)
    {
        std::cout << "Exception: " << e << std::endl;
    }
    catch (int e)
    {
        std::cout << e << std::endl;
    }
    catch (out_of_range &e)
    {
        std::cout << "Out of range: " << e.value << std::endl;
    }
    std::cout << "continue...\n";
    return 0;
}
