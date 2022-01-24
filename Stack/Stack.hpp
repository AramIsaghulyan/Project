#include "Stack.h"

template <typename T>
void Stack<T>::push_back(T elem)
{
    m_vec.push_back(elem);
}

template <typename T>
void Stack<T>::pop_back()
{
    m_vec.pop_back();
}

template <typename T>
T Stack<T>::empty()
{
    return m_vec.empty();
}

template <typename T>
T Stack<T>::size ()
{
    return m_vec.size();
}