#include "Deque.hpp"

template <typename T>
T& Deque<T>::operator[] (int index) 
{
    if (index >= vec1.size() + vec2.size()) 
    {
        std::cout << "Error out of range"<<;
        exit(0);
    }
    else if(index >= vec1.size()) {
        return vec2[index - vec1.size()];
    }
    return vec1[vec1.size()-index - 1];
}

template <class T>
void Deque<T>::push_back(T elem) 
{
    vec2.push_back(element);
}

template <class T>
void Deque<T>::push_front(T elem) 
{
    std::reverse(vec1.begin(),vec1.end());
    vec1.push_back(elem);
    std::reverse(vec1.begin(),vec1.end());
}

template <class T>
bool Deque<T>::is_empty() 
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int Deque<T>::size() 
{
    return vec1.size() + vec2.size();
}

template <class T>
void Deque<T>::pop_back() 
{
    vec2.pop_back();
}

template <class T>
void Deque<T>::pop_front() 
{
    vec1.pop_back();
}
