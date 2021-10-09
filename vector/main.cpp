#include <iostream>
#include "Vector1.h"

int main()
{
    Vector V;
    V.push_back (10);
    V.push_back (15);
    V.push_back(7) ;
  //  V.push_back(8);
    //std::cout << V.begin ();
    //V.empty();
    //V.capacity();
    V.resize (8,8);
    for(int i = 0 ; i < V.size() ;++i)
    {
        std::cout<< V.at(i) << "  ";
    }
    std::cout << V.capacity() << std::endl;

}