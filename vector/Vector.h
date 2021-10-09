#include <iostream>
#ifndef _Vector_
#define _Vector_
class Vector
{
public:

    Vector ();
    ~ Vector ();

public:
    
    void clear ();
    void shrink_to_fit();
    int * data ();
    void resize (int,int);
    int capacity ();
    void erase (int);
    int size()const;
    void insert (int,int);
    int begin ();
    bool empty ();
    void push_back (int);
    int at (int);
    void pop_back ();

private:

    int m_capacity;
    int m_size;
    int * m_buffer;

};
#endif //_Vector_