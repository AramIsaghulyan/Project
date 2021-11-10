#include "Tic_Tac_Toe.h"

void Tic_Tac_Toe::set_name1(std::string name1)
{
    m_player1 = name1;
}

void Tic_Tac_Toe::set_name2(std::string name)
{
    m_player2 = name;
}

void Tic_Tac_Toe::display()
{
    std::system ("clear");
    std::cout<< "_______" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << "|" << board [i][j];
        }
        std::cout << "|\n_______" << std::endl;
    }
}

void Tic_Tac_Toe::step()
{
    if(key == 'O')
    {
        v:
        std::cout << m_player1 << " " << " Enter index in range of 0 - 2" << std::endl;
        std::cin >> m_x;
        std::cin >> m_y;
        if(std::cin.good() == false) {
            exit(0);
        }
            if (m_x < 3 && m_y < 3 && board[m_x][m_y] == ' ')
            {
                board[m_x][m_y] = 'X';
                key = 'X';
                count ++;
                check();
            }
            else
            {
                key = 'O';
                goto v;
            }
    }
    if (count == 9 && !check())
    {
        std::cout << "There is no winner:" << std::endl;
        exit (0);
    }
    display();
    if (key == 'X')
    {
        x:
        std::cout << m_player2 << " " << " Enter index in range of 0 - 2" << std::endl;
        std::cin >> m_x;
        std::cin >> m_y;
        if (m_x < 3 && m_y < 3 && board[m_x][m_y] == ' ')
        {
            board[m_x][m_y] = 'O';
            key = 'O';
            count ++;
            check();
        }
        else
        {
            key = 'X';
            goto x;
        }
    }
    if (count == 9 && !check())
    {
        std::cout << "There is no winner:" << std::endl;
        exit (0);
    }
}

void Tic_Tac_Toe::play ()
{
    std::string str;
    std::cout << "Enter the first player name" << std::endl;
    std::getline(std::cin,str);
    set_name1(str);
    std::string str1;
    std::cout << "Enter the second player name" << std::endl;
    std::getline (std::cin,str1);
    set_name2(str1);
    while (!check())
    {
        display();
        step();
    }
}

bool Tic_Tac_Toe::check ()
{
    if (check_dioganal() || check_horizontal() || check_vertical())
    {
        play_again();
    }
    return false;
}

bool Tic_Tac_Toe::check_dioganal ()
{
    if (board[0][0] == 'X' && board[1][1] == 'X' && board [2][2] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][0] == 'O' && board[1][1] == 'O' && board [2][2] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][2] == 'X' && board[1][1] == 'X' && board [2][0] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board [2][0] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Tic_Tac_Toe::check_vertical ()
{
    if (board[0][0] == 'X' && board[1][0] == 'X' && board [2][0] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][0] == 'O' && board[1][0] == 'O' && board [2][0] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][1] == 'X' && board[1][1] == 'X' && board [2][1] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][1] == 'O' && board[1][1] == 'O' && board [2][1] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][2] == 'X' && board[1][2] == 'X' && board [2][2] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][2] == 'O' && board[1][2] == 'O' && board [2][2] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Tic_Tac_Toe::check_horizontal ()
{
    if (board[0][0] == 'X' && board[0][1] == 'X' && board [0][2] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[0][0] == 'O' && board[0][1] == 'O' && board [0][2] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    if (board[1][0] == 'X' && board[1][1] == 'X' && board [1][2] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[1][0] == 'O' && board[1][1] == 'O' && board [1][2] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    if (board[2][0] == 'X' && board[2][1] == 'X' && board [2][2] == 'X')
    {
        std::cout << m_player1 <<" Won the game" << std::endl;
        return true;
    }
    if (board[2][0] == 'O' && board[2][1] == 'O' && board [2][2] == 'O')
    {
        std::cout << m_player2 <<" Won the game" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Tic_Tac_Toe::play_again()
{
    std::string tmp;
    std::cout << "Do you want to play again (YES or NO)" << std::endl;
    std::cin >> tmp;
    std::cin.get();
    if (tmp == "YES")
    {
        count = 0;
        clear_board();
        display();
        step();
    }
    else
    {
        exit(0);
    }
}

void Tic_Tac_Toe::clear_board()
{
    for(int i = 0;i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            board[i][j]=' ';
        }
    }
}