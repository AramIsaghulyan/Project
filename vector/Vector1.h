#include <iostream>
#include "Vector.h"

Vector::Vector ()
{
    m_capacity = 1;
    m_size = 0;
    m_buffer = new int [m_capacity];
}
Vector::~Vector()
{
    delete[]m_buffer;
}

void Vector::push_back (int elem)
{
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
        int *tmp = new int [m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            tmp [i] = m_buffer [i];
        }
        delete [] m_buffer;
        m_buffer = tmp;
    }
    m_buffer[m_size] = elem;
    m_size++;
}

int Vector::at (int index)
{
    if (index < m_size && index >= 0)
    {
        return m_buffer [index];
    }
    return -1;
}

void Vector::pop_back ()
{
    m_size--;
}

bool Vector::empty ()
{
    if (m_size == 0)
    {
        std::cout << "Vector is empty" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Vector is not empty" << std::endl;
        return false;
    }
}

int Vector::begin ()
{
    int index = m_buffer[0];
    return index;
}

int Vector::size () const {return m_size;}


void Vector::insert (int index,int elem)
{
    if (m_size < m_capacity)
    {
        for (int i = m_size; i > index; --i)
        {
            m_buffer[i] = m_buffer[i-1];
        }
        m_buffer[index]=elem;
    }
    else
    {
        m_capacity *=2;
        int *tmp = new int [m_capacity];
        int i ;
        for (i = 0; i < index ;++i)
        {
            tmp[i] = m_buffer[i];
        }
        tmp[index] = elem;
        for( ; i < m_size; ++i)
        {
            tmp[i+1] = m_buffer[i];            
        }
        delete [] m_buffer;
        m_buffer = tmp ;
    }
    m_size++;
}

void Vector::erase (int index)
{
    if (index < m_size && index >= 0)
    {
        for (int i = index; i < m_size; ++i)
        {
            m_buffer[i] = m_buffer[i+1];
        }
        --m_size;
    }
}

void Vector::clear ()
{
    m_size = 0;
    m_capacity = 1;
    delete [] m_buffer;
    m_buffer = nullptr;
}

int Vector::capacity ()
{
    return m_capacity;
}

int *Vector::data ()
{
    return m_buffer;
}

void  Vector::shrink_to_fit()
{
    if (m_size == m_capacity)
    {
        return;
    }
    int *tmp = new int [m_size];
    for (int i = 0; i < m_size; ++i)
    {
        tmp[i] = m_buffer[i];
    }
    delete [] m_buffer;
    m_buffer = tmp;
    m_capacity = m_size;
}

void Vector::resize (int tmp,int size)
{
    if (size <= m_capacity)
    {
        m_size = size;
        for (int i = 0; i < m_size; ++i)
        {
            m_buffer[i] = tmp;
        }
    }
    else
    {
        int new_size = m_size + size;
        int *temp = new int[2*new_size];
        for (int i = 0; i < m_size; ++i)
        {
            temp[i] = m_buffer[i];
        }
        for (int i = m_size; i < new_size; ++i)
        {
            temp[i] = tmp;
        }
        m_size = new_size;
        m_capacity = 2*m_size;
        delete [] m_buffer;
        m_buffer = temp;
        temp = nullptr;
    }
}
