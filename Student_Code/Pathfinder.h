
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
    string m_Maze_string;
public:
    Pathfinder();
    
    string getMaze();
    void createRandomMaze();
    bool importMaze(string file_name);
    vector<string> solveMaze();
};
