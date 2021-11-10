#include "Count.h"

std::ostream & operator<< (std::ostream & os,Counter & obj)
{
    os << obj.ID;
    return os;
}

Counter::Counter()
{
    ID = ++count;
}

Counter::~Counter()
{
    --count;
}