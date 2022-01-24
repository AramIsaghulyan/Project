#ifndef _Deque_
#define _Deque_

#include <vector>
#include <algorithm>

template <typename T>
class Deque 
{
public:
    T& operator[] (int index);
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    bool is_empty();
    int size();
private:
    std::vector<T> vec1;
    std::vector<T> vec2;
};

#endif // _Deque_
