
#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                m_Maze[i][j][k] = 1;
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
    ifstream in_file;
    in_file.open(file_name);
    
    int rIn = -1;
    int counter = 0;
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                in_file >> rIn;
                if (rIn == -1)
                {
                    return false;
                }
                else if (rIn > 1)
                {
                    return false;
                }
                m_Maze[i][j][k] = rIn;
                counter++;
            }
        }
    }
    if (m_Maze[0][0][0] == 0 || m_Maze[4][4][4] == 0)
    {
        return false;
    }
    if (counter != 125)
    {
        return false;
    }
    return true;
}

vector<string> Pathfinder::solveMaze()
{
    vector<string> s;
    return s;
}






