
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
    cout << "getMaze()" << endl;
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
    cout << "createRandomMaze()" << endl;
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
    cout << "importMaze()" << file_name << endl;
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
                if (i == 0 && j == 0 && k == 0)
                {
                    if (rIn == 0)
                    {
                        return false;
                    }
                }
                if (i == 4 && j == 4 && k == 4)
                {
                    if (rIn == 0)
                    {
                        return false;
                    }
                }
                counter ++;
            }
        }
    }
    if (counter != 125)
    {
        return false;
    }
    
    ifstream in_file2;
    in_file2.open(file_name);
    for (int i = 0; i < MAZE_SIDE; i++) //x loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //z loop
            {
                in_file >> rIn;
                m_Maze[i][j][k] = rIn;
                counter++;
            }
        }
    }
    
    return true;
}

vector<string> Pathfinder::solveMaze()
{
    cout << "solveMaze()" << endl;
    vector<string> s;
    return s;
}






