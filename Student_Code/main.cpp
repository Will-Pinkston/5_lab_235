//
//  main.cpp
//  5_lab_tester
//
//  Created by William Pinkston on 10/10/16.
//  Copyright © 2016 Xunil_programming. All rights reserved.
//

#include <iostream>

#include "Factory.h"
#include "PathfinderInterface.h"
#include "Pathfinder.h"

using namespace std;

int main(int argc, const char * argv[]) {
    PathfinderInterface* pather = Factory::createPathfinder();
    string one;
    getline(cin,one);
    one = "/Users/Howl/Documents/BYU/CS/CS_235/lab5/Mazes/" + one;
    pather->importMaze(one);
    cout << pather->getMaze();
    vector<string> path = pather->solveMaze();
    if (path.size() == 0)
    {
        cout << "no path" << endl;
    }
    else
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << endl;
        }
    }

    
    return 0;
}
