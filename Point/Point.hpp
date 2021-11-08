#include "Point.h"

void Point::set_inf ()
{
    std::cout << "Enter the x coordinates:" << std::endl;
    std::cin >> m_x;
    std::cout << "Enter the y coordinates:" << std::endl;
    std::cin >> m_y;
}

void Point::get_coord ()
{
    std::cout << "Coordinats of the new points is: " << " x " << m_x << ";" <<" y " << m_y << std::endl;
}

Point  Point::operator+(const Point & oth)
{
    Point r;
    r.m_x = this->m_x + oth.m_x;
    r.m_y = this->m_y + oth.m_y;
    return r;
}

Point  Point::operator-(const Point & oth)
{
    Point r;
    r.m_x = this->m_x - oth.m_x;
    r.m_y = this->m_y - oth.m_y;
    return r;
}

Point & Point::operator=(const Point & oth)
{
    this->m_x = oth.m_x;
    this->m_y = oth.m_y;
    return *this;
}