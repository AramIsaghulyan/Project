#include <iostream>
class Point
{

public:
    void set_inf ();
    void get_coord ();
    Point operator +(const Point & oth);
    Point operator -(const Point & oth);
    Point & operator =(const Point & oth);
private:
    double m_x;
    double m_y;
};