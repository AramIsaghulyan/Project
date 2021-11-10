#include "Calculator.h"

void Calculator::run ()
{
    double x;
    double y;
    std::cout << "Enter the first numbere:" << std::endl;
    std::cin >> x;
    std::cout << "Enter the second number:" << std::endl;
    std::cin >> y;
    set (x,y);
    std::cout << "The arithmetic operation of two numbers is equal (+)  " << add() << std::endl;
    std::cout << "The arithmetic operation of two numbers is equal (-)  " << sub() << std::endl;
    std::cout << "The arithmetic operation of two numbers is equal (*)  " << mul() << std::endl;
    std::cout << "The arithmetic operation of two numbers is equal (/)  " << div() << std::endl;
}

void Calculator::set (double x, double y)
{
    m_x = x;
    m_y = y;
}

double Calculator::add ()
{
    return m_x + m_y;
}

double Calculator::sub ()
{
    return m_x - m_y;
}

double Calculator::mul ()
{
    return m_x * m_y;
}

double Calculator::div ()
{
    if (m_y == '0')
    {
        std::cout << "The second number cannot be 0։" << std::endl;
    }
    return m_x / m_y;
}