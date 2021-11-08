#include "Person.hpp"

int main ()
{
    
    Person ob;
    ob.set_info();
    std::cout << ob.get_name() << std::endl;
    std::cout << ob.get_age() << std::endl;
    std::cout << ob.get_mail() << std::endl;
    Person obj;
    obj = ob;
    std::cout << obj.get_name() << std::endl;
    std::cout << obj.get_age() << std::endl;
    std::cout << obj.get_mail() << std::endl;
}