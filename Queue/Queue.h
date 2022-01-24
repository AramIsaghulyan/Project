#ifndef _Queue_
#define _Queue_

#include <iostream>
#include <deque>


template <typename T>
class Queue
{
public:
    friend std::ostream& operator << (std::ostream& os, Queue<T>& oth)
    {
        for (const auto& it : oth.m_deq)
        {
            os << it;
        }
        return os;
    }
public:
    Queue () = default;
    Queue (const Queue& src)
    {
        this->m_deq = src.m_deq;
    }
    Queue & operator = (const Queue& rhs)
    {
        this->m_deq = rhs.m_deq;
        return *this;
    }
public:
    void pop ();
    void push (T);
    T front ();
    T back ();
    T empty ();
    T size ();
private:
    std::deque<T> m_deq;
};

#endif // _Queue_