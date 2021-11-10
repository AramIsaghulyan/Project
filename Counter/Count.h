#include <iostream>

class Counter
{
public:
    friend std::ostream & operator << (std::ostream & os,Counter & obj);
    Counter();
    ~Counter(); 
private:
    static int count;
    int ID;
};

