#include "Utility.hpp"

int main ()
{
    Utility obj;
    std::string str;
    std::getline(std::cin,str);
    std::cout << obj.isNumber(str);
}