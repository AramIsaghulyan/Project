#include <iostream>

class Calculator
{
public:
    void run ();
    void set (double,double);
    double add ();
    double sub ();
    double mul ();
    double div ();

private:
    double m_x;
    double m_y;
};