#include "Point.hpp"

int main ()
{
    Point sum;
    Point obj;
    obj.set_inf();
    Point ob;
    ob.set_inf();
    std::cout << "Whot do you want to do with the first and the second points,answers: F + S (1), S - F(2), F - S(3)" << std::endl;
    char operation;
    std::cin >> operation;
    switch (operation)
    {
    case '1':
        sum = obj + ob;
        sum.get_coord();
        break;
    case '2':
        sum = obj - ob;
        sum.get_coord();
        break;
    case '3':
        sum = ob - obj;
        sum.get_coord();
        break;
    default:
        break;
    }
}