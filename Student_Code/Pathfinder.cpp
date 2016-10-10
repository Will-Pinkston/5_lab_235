
#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                m_Maze[i][j][k] = 0;
            }
        }
    }
}

string Pathfinder::getMaze()
{
    stringstream ss;
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                ss << m_Maze[i][j][k] << " ";
            }
            ss << "\n";
        }
        ss << "\n";
    }
    return ss.str();
}
void Pathfinder::createRandomMaze()
{
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                m_Maze[i][j][k] = rand()%2;
            }
        }
    }
    m_Maze[0][0][0] = 1;
    m_Maze[4][4][4] = 1;
}
bool Pathfinder::importMaze(string file_name)
{
    return false;
}
vector<string> Pathfinder::solveMaze()
{
    vector<string> s;
    return s;
}






