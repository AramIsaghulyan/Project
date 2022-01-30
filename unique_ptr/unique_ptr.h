#include <iostream>

template <typename T>
class unique_ptr
{
public:
    unique_ptr () : m_ptr{nullptr} {}
    unique_ptr (T *ptr) : m_ptr {ptr} {}
    unique_ptr (unique_ptr && src) {m_ptr = src.m_ptr; src.m_ptr = nullptr;}
    unique_ptr (const unique_ptr& ob) = delete;
    ~unique_ptr () {delete m_ptr;}
public:
    unique_ptr& operator = (const unique_ptr& ob) = delete;
    unique_ptr& operator *() {return *m_ptr;}
    unique_ptr& operator ->() {return m_ptr;}
private:
    T *m_ptr;
};