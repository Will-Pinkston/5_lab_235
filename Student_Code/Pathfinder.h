
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

#include "PathfinderInterface.h"

#define MAZE_SIDE 5


using namespace std;

class Pathfinder : public PathfinderInterface
{
private:
    int m_Maze[5][5][5];
    int m_Path[5][5][5];
    string m_Maze_string;
    int x /*= 4*/;
    int y /*= 4*/;
    int z /*= 4*/;
    stringstream add;
//    vector<string> m_MazePath;
public:
    Pathfinder();
    
    string getMaze();
    void createRandomMaze();
    bool importMaze(string file_name);
    vector<string> solveMaze();
};
