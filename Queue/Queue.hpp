#include "Queue.h"

template <typename T>
void Queue<T>::pop ()
{
    m_deq.pop_front();
}

template <typename T>
void Queue<T>::push(T elem)
{
    m_deq.push_back(elem);
}

template <typename T>
T Queue<T>::front()
{
    return m_deq.front();
}

template <typename T>
T Queue<T>::back()
{
    return m_deq.back();
}

template <typename T>
T Queue<T>::empty()
{
    return m_deq.empty();
}

template <typename T>
T Queue<T>::size()
{
    return m_deq.size();
}