#ifndef _Stack_
#define _Stack_

#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
    Stack () = default;
    Stack (const Stack& src)
    {
        this->m_vec = src.m_vec;
    }
    Stack& operator = (const Stack& rhs)
    {
        this->m_vec = rhs.m_vec;
        return *this;
    }

public:
    friend std::ostream& operator << (std::ostream& os,Stack<T>& oth)
    {
        for (const auto& it : oth.m_vec)
        {
            os << it;
        }
        return os;
    }

public:
    void push_back (T);
    void pop_back ();
    T empty ();
    T size ();

private:
    std::vector <T> m_vec;
};

#endif //_Stack_