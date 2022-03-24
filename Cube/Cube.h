#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Cube
{
public:
    Cube () = default;
    Cube (std::string&);
    void code ();
private:
    std::ofstream fin;
    std::ifstream oin;
    std::string path;
private:
    void readFile ();
    void change_string ();
    void text_print ();
    void cube_index_and_chenge ();
    void cube_move();
    void cube_up(int);
    void cube_down(int);
    void cube_left(int);
    void cube_right(int);
    void decode();
private:
    std::string code_inform; 
    const int m_cube_size = 8;
    std::string m_code_string;
    std::vector<std::string>m_vec_string;
};