
#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    for (int i = 0; i < MAZE_SIDE; i++) //z loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //x loop
            {
                m_Maze[i][j][k] = 1;
                m_Path[i][j][k] = 0;
            }
        }
    }
}

string Pathfinder::getMaze()
{
    stringstream ss;
    for (int i = 0; i < MAZE_SIDE; i++) //z loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //x loop
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
    for (int i = 0; i < MAZE_SIDE; i++) //z loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //x loop
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
    x = 4;
    y = 4;
    z = 4;
    ifstream in_file;
    in_file.open(file_name);
    int rIn = -1;
    int counter = 0;
    while (in_file >> rIn)
    {
        counter++;
        if (rIn == -1)
        {
            return false;
        }
        else if (rIn != 1 && rIn != 0)
        {
            return false;
        }
        if (counter == 1 && rIn == 0)
        {
            return false;
        }
        if (counter == 125 && rIn == 0)
        {
            return false;
        }
    }
    in_file.close();
    if (counter != 125)
    {
        return false;
    }
    
    ifstream in_file2;
    in_file2.open(file_name);
    for (int i = 0; i < MAZE_SIDE; i++) //z loop
    {
        for (int j = 0; j < MAZE_SIDE; j++) //y loop
        {
            for (int k = 0; k < MAZE_SIDE; k++) //x loop
            {
                in_file2 >> rIn;
                m_Maze[i][j][k] = rIn;
                counter++;
            }
        }
    }
    in_file2.close();
    return true;
}

vector<string> Pathfinder::solveMaze()
{
    vector<string> s;
    s.push_back("");
    m_Path[z][y][x] = 1;
    if (x == 0 && y == 0 && z == 0)
    {
        s.push_back("(0,0,0)");
        return s;
    }
    else
    {
        if (x != 0 && m_Maze[z][y][x-1] == 1 && m_Path[z][y][x-1] == 0)
        {
            x--;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            x++;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }
        if (y != 0 && m_Maze[z][y-1][x] == 1 && m_Path[z][y-1][x] == 0)
        {
            y--;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            y++;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }
        if (z != 0 && m_Maze[z-1][y][x] == 1 && m_Path[z-1][y][x] == 0)
        {
            z--;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            z++;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }
        if (x != 4 && m_Maze[z][y][x+1] == 1 && m_Path[z][y][x+1] == 0)
        {
            x++;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            x--;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }
        if (y != 4 && m_Maze[z][y+1][x] == 1 && m_Path[z][y+1][x] == 0)
        {
            y++;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            y--;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }
        if (z != 4 && m_Maze[z+1][y][x] == 1 && m_Path[z+1][y][x] == 0)
        {
            z++;
            s = solveMaze();
            m_Path[z][y][x] = 0;
            z--;
            if (s.size() > 0 && s.front() == "(0,0,0)")
            {
                stringstream add;
                add << "(" << x << "," << y << "," << z << ")";
                s.push_back(add.str());
                return s;
            }
            else
            {
                m_Path[z][y][x] = 0;
            }
        }

        else return s;
    }
    return s;
}



