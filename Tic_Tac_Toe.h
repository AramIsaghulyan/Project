#ifndef _TIC_TAC_TOE_
#define _TIC_TAC_TOE_ 
#include <iostream>
#include <string>

class Tic_Tac_Toe
{
    private:
    char board [3][3];
    int m_x;
    int m_y;
    std::string m_player1;
    std::string m_player2;

    public:

    Tic_Tac_Toe() : m_x {0}, m_y {0}, m_player1{""}, m_player2 {""}
    {
        for(int i = 0;i < 3 ; ++i)
            for(int j = 0 ; j < 3 ; ++j)
                board[i][j]=' ';
    }
    void play ();
    bool check ();
    void step ();

    private:

    void display ();
    void play_again();
    void clear_board();
    bool is_empty_board();
    void set_name1(std::string);
    void set_name2(std::string);
    bool check_dioganal ();
    bool check_vertical ();
    bool check_horizontal ();

    char key = 'O';
    static int count;
};
#endif // _TIC_TAC_TOE_
